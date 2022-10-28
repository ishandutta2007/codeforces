#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<string> grid;
    while (t--) {
        int r, c;
        cin >> r >> c;
        grid.resize(r);
        for (auto& i : grid) {
            cin >> i;
        }

        // 0
        bool ok = true;
        for (auto& i : grid) {
            for (auto j : i) {
                if (j == 'P') {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << 0 << '\n';
            continue;
        }

        // 1
        bool tmp = true;
        for (int i = 0; i < c; ++i) {
            if (grid[0][i] == 'P') {
                tmp = false;
            }
        }
        ok |= tmp;
        tmp = true;
        for (int i = 0; i < c; ++i) {
            if (grid.back()[i] == 'P') {
                tmp = false;
            }
        }
        ok |= tmp;
        tmp = true;
        for (int i = 0; i < r; ++i) {
            if (grid[i][0] == 'P') {
                tmp = false;
            }
        }
        ok |= tmp;
        tmp = true;
        for (int i = 0; i < r; ++i) {
            if (grid[i].back() == 'P') {
                tmp = false;
            }
        }
        ok |= tmp;
        if (ok) {
            cout << 1 << '\n';
            continue;
        }

        // 2
        ok = grid[0][0] == 'A' || grid[0].back() == 'A' ||
                grid.back()[0] == 'A' || grid.back().back() == 'A';
        for (int i = 1; i < r - 1 && !ok; ++i) {
            tmp = true;
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 'P') {
                    tmp = false;
                }
            }
            ok |= tmp;
        }
        for (int i = 1; i < c - 1 && !ok; ++i) {
            tmp = true;
            for (int j = 0; j < r; ++j) {
                if (grid[j][i] == 'P') {
                    tmp = false;
                }
            }
            ok |= tmp;
        }
        if (ok) {
            cout << 2 << '\n';
            continue;
        }

        // 3
        for (int i = 0; i < c && !ok; ++i) {
            ok = (grid[0][i] == 'A');
        }
        for (int i = 0; i < c && !ok; ++i) {
            ok = (grid.back()[i] == 'A');
        }
        for (int i = 0; i < r && !ok; ++i) {
            ok = (grid[i][0] == 'A');
        }
        for (int i = 0; i < r && !ok; ++i) {
            ok = (grid[i].back() == 'A');
        }
        if (ok) {
            cout << 3 << '\n';
            continue;
        }

        // 4
        for (auto& i : grid) {
            for (auto j : i) {
                if (j == 'A') {
                    ok = true;
                }
            }
        }
        cout << (ok ? "4" : "MORTAL") << '\n';
    }
}