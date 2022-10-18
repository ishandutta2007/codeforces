#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> c(h, vector<int>(w));
    vector<vector<pair<int, int>>> b(k);
    vector<vector<vector<int>>> d(k, vector<vector<int>>(h, vector<int>(w, 1e9)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c[i][j];
            c[i][j]--;
            b[c[i][j]].emplace_back(i, j);
        }
    }
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    for (int l = 0; l < k; l++) {
        queue<pair<int, int>> que;
        for (auto p : b[l]) {
            d[l][p.first][p.second] = 0;
            que.emplace(p);
        }
        vector<bool> was(k);
        was[l] = true;
        while (!que.empty()) {
            int x, y;
            tie(x, y) = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && d[l][nx][ny] > d[l][x][y] + 1) {
                    d[l][nx][ny] = d[l][x][y] + 1;
                    que.emplace(nx, ny);
                }
            }
            if (!was[c[x][y]]) {
                was[c[x][y]] = true;
                for (auto p : b[c[x][y]]) {
                    if (d[l][p.first][p.second] > d[l][x][y] + 1) {
                        d[l][p.first][p.second] = d[l][x][y] + 1;
                        que.emplace(p.first, p.second);
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for (int l = 0; l < k; l++) {
            ans = min(ans, d[l][r1][c1] + d[l][r2][c2] + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}