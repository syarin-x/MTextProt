#include "CEditEngine.h"
#include <sstream>
#include <iomanip>
#include "mtxtprot.h"

enum EDIT_TYPE{
    COMMAND_MODE = 0
    ,INSERT_MODE
    ,DEBUG_MODE
    ,QUIT_OPERATION
};

enum DIRECTION{
    UP = 0x41
    ,DOWN
    ,RIGHT
    ,LEFT
};


class CEditControl {
    CEditEngine* m_cediteng;
    char* m_filename;
    EDIT_TYPE m_mode;
    MPos m_cursor;
    LINES m_lines;

    long m_iStartLine;
    long m_iPageLine;
    long m_iConsoleRows;
    long m_iConsoleColumns;

    // メッセージ - イベント関数群
    void message_loop();
    void message_procedure(MESSAGE& msg);
    void OnKeyPress(char key);
    void OnChangeWindowSize(MSize& ms);
    void OnPaint();

    // 表示用関数群
    void disp_sub(int StartLine, int dispLineNum);
    std::string GetFileDispName();
    void disp_filename();
    void disp_mode();
    void disp();
    void disp(int StartLine, int dispLineNum);
    void disp_cursor();
    void disp_clear();

    // キー操作関数群
    bool keygen(char key);
    void keygen_command_mode(char key);
    void keygen_insert_mode(char key);
    void keygen_commonkey(char key);
    void update_winsize();
    void PageUp();
    void PageDown();
    void move_cursor(char dir);

    // CEditEngine操作関数
    void update_lines();

public:
    CEditControl();
    ~CEditControl(){};
    void run();
    bool set_filename(char* filename);
};
