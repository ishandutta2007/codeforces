#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

vector<array<int, 2>> que;
int degree[N][N], n, m;
string grid[N];

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

void update(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        degree[i][j] = 0;
    }
    
    if (valid(i - 1, j) && ++degree[i - 1][j] == 3) {
        que.push_back({i - 1, j});
    }
    if (valid(i + 1, j) && ++degree[i + 1][j] == 3) {
        que.push_back({i + 1, j});
    }
    if (valid(i, j - 1) && ++degree[i][j - 1] == 3) {
        que.push_back({i, j - 1});
    }
    if (valid(i, j + 1) && ++degree[i][j + 1] == 3) {
        que.push_back({i, j + 1});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; ++i) {
        update(i, -1), update(i, m);
    }

    for (int i = 0; i < m; ++i) {
        update(-1, i), update(n, i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                update(i, j);
            }
        }
    }

    while (!que.empty()) {
        auto [i, j] = que.back();
        que.pop_back();

        if (degree[i][j] == 0) {
            continue;
        } else if (degree[i][j] == 4) {
            cout << "Not unique\n";
            exit(0);
        }

        if (valid(i - 1, j)) {
            grid[i - 1][j] = '^', grid[i][j] = 'v';
            update(i - 1, j);
        } else if (valid(i + 1, j)) {
            grid[i][j] = '^', grid[i + 1][j] = 'v';
            update(i + 1, j);
        } else if (valid(i, j - 1)) {
            grid[i][j - 1] = '<', grid[i][j] = '>';
            update(i, j - 1);
        } else {
            grid[i][j] = '<', grid[i][j + 1] = '>';
            update(i, j + 1);
        }

        update(i, j);
    }

    for (int i = 0; i < n; ++i) {
        if (count(grid[i].begin(), grid[i].end(), '.') > 0) {
            cout << "Not unique\n";
            exit(0);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }
}