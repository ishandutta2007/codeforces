#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int a[maxn];
char s[maxn][maxn];
queue<tuple<int, int, int>> q[maxn];

int main() {
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < p; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != '.' && s[i][j] != '#')
                s[i][j] -= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.' || s[i][j] == '#') continue;
            q[s[i][j] - '0'].emplace(0, i, j);
        }
    }
    int r = 0;
    while (true) {
        bool kp = false;
        for (int i = 0; i < p; ++i) {
            if (q[i].empty()) continue;
            kp = true;
            while ((int)q[i].size() > 0) {
                int w, x, y;
                tie(w, x, y) = q[i].front();
                if (w >= (r + 1) * a[i]) break;
                q[i].pop();
                for (int k = 0; k < 4; ++k) {
                    int tx = x + dx[k], ty = y + dy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                    if (s[tx][ty] != '.') continue;
                    s[tx][ty] = (char)(i + '0');
                    q[i].emplace(w + 1, tx, ty);
                }
            }
        }
        ++r;
        if (!kp) break;
        // for (int i = 0; i < n; ++i) {
            // for (int j = 0; j < m; ++j) putchar(s[i][j]);
            // puts("");
        // }
        // puts("");
    }
    for (int i = 0; i < p; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k)
                ans += s[j][k] - '0' == i;
        }
        printf("%d ", ans);
    }
    puts("");
    return 0;
}