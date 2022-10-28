#include <bits/stdc++.h>
using namespace std;

vector<int> deltaR = {0, -1, 0, 1};
vector<int> deltaC = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> cells(k + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            cells[grid[i][j]].emplace_back(i, j);
        }
    }

    vector<vector<vector<int>>> dist(k + 1, vector<vector<int>>(n + 1,
            vector<int>(m + 1, 1e9)));
    for (int i = 1; i <= k; ++i) {
        queue<pair<int, int>> bfs;
        vector<bool> vstd(k + 1);
        vstd[i] = true;
        for (auto j : cells[i]) {
            int r, c;
            tie(r, c) = j;
            bfs.emplace(r, c);
            dist[i][r][c] = 0;
        }
        while (!bfs.empty()) {
            int r, c;
            tie(r, c) = bfs.front();
            bfs.pop();
            if (!vstd[grid[r][c]]) {
                vstd[grid[r][c]] = true;
                for (auto j : cells[grid[r][c]]) {
                    int nR, nC;
                    tie(nR, nC) = j;
                    if (dist[i][nR][nC] == 1e9) {
                        bfs.emplace(nR, nC);
                        dist[i][nR][nC] = dist[i][r][c] + 1;
                    }
                }
            }
            for (int j = 0; j < 4; ++j) {
                int nR = r + deltaR[j];
                int nC = c + deltaC[j];
                if (nR >= 1 && nR <= n && nC >= 1 && nC <= m &&
                        dist[i][nR][nC] == 1e9) {
                    bfs.emplace(nR, nC);
                    dist[i][nR][nC] = dist[i][r][c] + 1;
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sol = abs(r1 - r2) + abs(c1 - c2);
        for (int i = 1; i <= k; ++i) {
            sol = min(sol, dist[i][r1][c1] + 1 + dist[i][r2][c2]);
        }
        cout << sol << '\n';
    }
}