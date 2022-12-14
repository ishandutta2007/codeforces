#include <iostream>
//#include <string>
#include <vector>

struct pos {
    int row, col;
    pos(int row1, int col1) : row (row1), col (col1) {};
};

const int tree = -1;

std::vector<std::vector<int>> grid; // why not std::string?
std::vector<std::vector<bool>> reached;

int startrow, startcol, endrow, endcol, n_row, n_col, result = 0;

std::vector<pos> dist_d, dist_d1 /* d+1 */;

void check(int row, int col) {
    if (grid[row][col] != tree && !reached[row][col]) {
        reached[row][col] = true;
        dist_d1.emplace_back(row, col);
        result += grid[row][col];
    }
}

int main() {

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cin >> n_row >> n_col;
    grid.resize(n_row); reached.resize(n_row);

    for (int row=0; row<n_row; ++row) {
        grid[row].resize(n_col); reached[row].resize(n_col, false);
        for (int col=0; col<n_col; ++col) {
            char ch;
            std::cin >> ch;
            if (ch == 'S') {
                grid[row][col] = 0;
                startrow=row; startcol=col;
            } else if (ch == 'T') {
                grid[row][col] = tree;
            } else if (ch == 'E') {
                grid[row][col] = 0;
                endrow=row; endcol=col;
            } else {
                grid[row][col] = static_cast<int>(ch) - 48; // char -> int
            }
        }
    }

    int d = 0;
    dist_d.emplace_back(endrow, endcol);

    while (!reached[startrow][startcol]) {
        /* now dist_d consists of all pos that reachable from E in d steps,
        dist_d1 is empty.
        */
        for (const pos & p : dist_d) {
            if (p.row > 0      ) check(p.row-1, p.col  );
            if (p.col > 0      ) check(p.row  , p.col-1);
            if (p.row < n_row-1) check(p.row+1, p.col  );
            if (p.col < n_col-1) check(p.row  , p.col+1);
        }
        ++d; std::swap(dist_d, dist_d1); dist_d1.clear();
    }

    std::cout << result;
}