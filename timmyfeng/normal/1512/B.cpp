#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> grid(n);
        for (auto &i : grid) {
            cin >> i;
        }

        vector<array<int, 2>> stars;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    stars.push_back({i, j});
                }
            }
        }

        auto [a, b] = stars[0];
        auto [c, d] = stars[1];

        if (a == c) {
            grid[a == 0][b] = grid[c == 0][d] = '*';
        } else if (b == d) {
            grid[a][b == 0] = grid[c][d == 0] = '*';
        } else {
            grid[a][d] = grid[c][b] = '*';
        }

        for (auto &i : grid) {
            cout << i << "\n";
        }
    }
}