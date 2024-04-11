#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> c(22, vector<int>(361));
        vector<vector<int>> s(22, vector<int>(361));
        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            if (op == "C") {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                if (t1 < t2) {
                    c[r][t1]++;
                    c[r][t2]--;
                } else {
                    c[r][0]++;
                    c[r][t2]--;
                    c[r][t1]++;
                    c[r][360]--;
                }
            } else {
                int r1, r2, t;
                cin >> r1 >> r2 >> t;
                s[r1][t]++;
                s[r2][t]--;
            }
        }
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 360; j++) {
                c[i][j + 1] += c[i][j];
                s[i + 1][j] += s[i][j];
            }
        }
        for (int i = 0; i < 22; i++) {
            c[i][360] = c[i][0];
            s[i][360] = s[i][0];
        }
        vector<vector<bool>> vis(21, vector<bool>(360));
        queue<pair<int, int>> que;
        que.emplace(0, 0);
        vis[0][0] = true;
        int dd[] = {1, 0, -1, 0};
        while (!que.empty()) {
            auto [r, t] = que.front();
            que.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dd[dir];
                int nt = t + dd[dir ^ 1];
                if (nr == 21 || nr == -1) {
                    continue;
                }
                nt = (nt + 360) % 360;
                if (vis[nr][nt]) {
                    continue;
                }
                if (r != nr) {
                    if (c[max(r, nr)][t]) {
                        continue;
                    }
                } else {
                    if (s[r][(abs(t - nt) == 359 ? 0 : max(t, nt))]) {
                        continue;
                    }
                }
                vis[nr][nt] = true;
                que.emplace(nr, nt);
            }
        }
        if (vis[20][0]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}