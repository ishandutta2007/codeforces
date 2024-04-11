#include <bits/stdc++.h>
using namespace std;

const int delta_i[] = {-1, 1, 0, 0};
const int delta_j[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &i : grid) {
            cin >> i;
        }

        vector<vector<bool>> free(n, vector<bool>(m));
        set<pair<int, int>> cell_queue;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    free[i][j] = true;
                    cell_queue.insert({i, j});
                } else if (grid[i][j] == '#') {
                    free[i][j] = true;
                }
            }
        }

        while (!cell_queue.empty()) {
            auto [i, j] = *cell_queue.begin();
            cell_queue.erase(cell_queue.begin());

            int adj_free = 0;
            for (int k = 0; k < 4; ++k) {
                int i_new = i + delta_i[k];
                int j_new = j + delta_j[k];

                if (0 <= i_new && i_new < n && 0 <= j_new && j_new < m) {
                    adj_free += free[i_new][j_new];
                } else {
                    adj_free++;
                }
            }

            free[i][j] = free[i][j] || adj_free >= 3;

            if (free[i][j]) {
                for (int k = 0; k < 4; ++k) {
                    int i_new = i + delta_i[k];
                    int j_new = j + delta_j[k];

                    if (0 <= i_new && i_new < n && 0 <= j_new && j_new < m) {
                        if (!free[i_new][j_new]) {
                            cell_queue.insert({i_new, j_new});
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    cout << (free[i][j] ? '+' : '.');
                } else {
                    cout << grid[i][j];
                }
            }
            cout << "\n";
        }
    }
}