#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct pos {
    int row, col;
    pos(int row1, int col1) : row (row1), col (col1) {};
} finish(1234,5678);

int n_row, n_col;
std::vector<std::vector<char>> prev;
std::vector<std::vector<bool>> safe;

std::queue<pos> bfs_queue;

char swap[128];

const int noswap = 0, swapped = 1, unknown = 2;
int swapud = unknown, swaplr = unknown;

void check(int r, int c, char backmove) {
    if (r >= 0 && r < n_row && c >= 0 && c < n_col) {
        if (safe[r][c] && prev[r][c] == '?') {
            bfs_queue.emplace(r, c);
            prev[r][c] = backmove;
        }
    }
}

pos exec(pos p, char mov) {
    if (((mov == 'U' || mov == 'D') ? swapud : swaplr) == swapped) mov = swap[mov];
    switch (mov) {
        case 'U': return pos(p.row-1, p.col);
        case 'D': return pos(p.row+1, p.col);
        case 'R': return pos(p.row, p.col+1);
        case 'L': return pos(p.row, p.col-1);
        default: return pos(-999, -999);
    }
}

int main() {
    swap['U'] = 'D'; swap['D'] = 'U';
    swap['L'] = 'R'; swap['R'] = 'L';

    std::cin >> n_row >> n_col;
    prev.resize(n_row);
    safe.resize(n_row);
    std::string line;
    for (int i = 0; i < n_row; ++i) {
        std::cin >> line;
        for (int j = 0; j < n_col; ++j) {
            char ch = line[j];
            if (ch == 'F') {
                ch = '.';
                finish.row = i; finish.col = j;
            }
            safe[i].push_back(ch == '.');
            prev[i].emplace_back('?');
        }
    }

    bfs_queue.push(finish);
    while (prev[0][0] == '?') {
        pos x = bfs_queue.front();
        bfs_queue.pop();
        check(x.row-1, x.col  , 'D');
        check(x.row+1, x.col  , 'U');
        check(x.row  , x.col-1, 'R');
        check(x.row  , x.col+1, 'L');
    }
    // Be careful with R==1 || C==1 and 0based

    pos cur (0, 0);
    while (cur.row != finish.row || cur.col != finish.col) {
        if (!safe[cur.row][cur.col]) {
            return 0;
        }
        char mov = prev[cur.row][cur.col];
        int *cur_swapq_ptr =(mov == 'U' || mov == 'D') ? &swapud : &swaplr;
        if (*cur_swapq_ptr == unknown) {
            int r, c;
            *cur_swapq_ptr = false;
            std::cout << mov << std::endl;
            std::cin >> r >> c;
            if (r == -1 || c == -1) return 0;
            --r; --c;
            pos newcur = exec(cur, mov);
            if (newcur.row != r || newcur.col != c) {
                *cur_swapq_ptr = true;
            }
            cur.row = r; cur.col = c;
        } else {
            if (((mov == 'U' || mov == 'D') ? swapud : swaplr) == swapped)
                mov = swap[mov];
            std::cout << mov << std::endl;
            std::cin >> cur.row >> cur.col;
            if (cur.row == -1 || cur.col == -1) return 0;
            --cur.row; --cur.col;
        }
    }
}