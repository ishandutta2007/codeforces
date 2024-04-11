#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<pair<int, int>>> gd(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
            gd[a[i][j]].emplace_back(i, j);
        }
    }

    constexpr int dx[4] = {1, 0, -1, 0};
    constexpr int dy[4] = {0, 1, 0, -1};
    constexpr int kInf = 1'000'000'000;

    vector<vector<int>> dist(k + k, vector<int>(k + k, kInf));
    vector<vector<vector<int>>> gds(k, vector<vector<int>>(n, vector<int>(m, -1)));
    for (int i = 0; i < k + k; ++i) dist[i][i] = 0;
    for (int i = 0; i < k; ++i) dist[i][i + k] = 1;

    for (int c = 0; c < k; ++c) {
        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(m, -1));
        for (auto p : gd[c]) {
            gds[c][p.first][p.second] = 0;
            d[p.first][p.second] = 0;
            q.push(p);
        }
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; ++i) {
                if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m) continue;
                if (d[x + dx[i]][y + dy[i]] == -1) {
                    d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
                    gds[c][x + dx[i]][y + dy[i]] = d[x][y] + 1;
                    q.emplace(x + dx[i], y + dy[i]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[c + k][a[i][j]] = min(dist[c + k][a[i][j]], d[i][j]);
            }
        }
    }
    for (int c = 0; c < k + k; ++c) {
        for (int i = 0; i < k + k; ++i) {
            for (int j = 0; j < k + k; ++j) dist[i][j] = min(dist[i][j], dist[i][c] + dist[c][j]);
        }
    }
    int q; scanf("%d", &q);
    while (q--) {
        int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        r1--, c1--, r2--, c2--;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        ans = min(ans, gds[a[r2][c2]][r1][c1] + 1);
        ans = min(ans, gds[a[r1][c1]][r2][c2] + 1);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (gds[i][r1][c1] == -1 || gds[j][r2][c2] == -1) continue;
                ans = min(ans, gds[i][r1][c1] + gds[j][r2][c2] + dist[i][j + k]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}