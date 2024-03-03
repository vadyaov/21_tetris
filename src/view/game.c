#include <stdio.h>
#include <ncurses.h>

#define CELL_W 4
#define CELL_H 2

#define WIDTH 42
#define HEIGHT 44

void print_board(WINDOW *menu_win /* ,GameInfo_t* gameinfo */);
void print_score(WINDOW *menu_win /* ,GameInfo_t* gameinfo */);

int main() {
  /* GameIngo_t *tetris_game = CreateBoard(20, 10); */
  /* UserAction_t action = Pause; */

  WINDOW *game_board;
  WINDOW *next;
  WINDOW *score;

  bool running = true;

	initscr();
	clear();
  curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
		



	game_board = newwin(HEIGHT + 2, WIDTH + 2, 0, 0);
  next       = newwin(CELL_H * 4 + 2, CELL_W * 4 + 2, 0, WIDTH + 2 + 1);
  score      = newwin(CELL_H * 4 + 2, CELL_W * 4 + 2, CELL_H * 4 + 2 + 1, WIDTH + 2 + 1);

	refresh();
	print_board(game_board/*, tetris_game */);
  print_board(next/*, tetris_game */);
  print_score(score /*, tetris_game */);
  
  while (running) {
    switch(getch()) {
      case KEY_UP: // rotate
        {
        }
      case KEY_LEFT: // move left
        {
        }
      case KEY_RIGHT: // move right
        {
        }
      case KEY_DOWN: // fall down
        {
        }
      case 'q': // quit
        {
          running = false;
          break;
        }
    }
    wrefresh(game_board);
  }

	refresh();
	clrtoeol();
	endwin();
	return 0;
}

void print_board(WINDOW *board_win) {
	box(board_win, 0, 0);
	wrefresh(board_win);
}

void print_score(WINDOW *score_win) {
	box(score_win, 0, 0);
	wrefresh(score_win);
}
