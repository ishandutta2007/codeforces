#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define mp make_pair
#define pii pair<int, int>
char a[101][101];
void inv (int x, int y) { if (a[x][y] == '1') a[x][y] = '0'; else a[x][y] = '1'; }

struct ANS { int x1, y1, x2, y2, x3, y3; } ans[101001]; int top;
void op (int x1, int y1, int x2, int y2, int x3, int y3) {
    ++top;
    ans[top].x1 = x1;
    ans[top].y1 = y1;
    ans[top].x2 = x2;
    ans[top].y2 = y2;
    ans[top].x3 = x3;
    ans[top].y3 = y3;
}

void solve (int x, int y) {
    vector <pii> v[2];
    v[a[x][y] - '0'].push_back(mp(x, y));
    v[a[x+1][y] - '0'].push_back(mp(x+1, y));
    v[a[x][y+1] - '0'].push_back(mp(x, y+1));
    v[a[x+1][y+1] - '0'].push_back(mp(x+1, y+1));
    if (v[1].size() == 4) {
        op(x, y, x, y + 1, x + 1, y);
        op(x + 1, y + 1, x, y, x + 1, y);
        op(x, y, x, y + 1, x + 1, y + 1);
        op(x + 1, y, x, y + 1, x + 1, y + 1);
        inv(x, y), inv(x + 1, y), inv(x, y + 1), inv(x + 1, y + 1);
    }
    else if (v[1].size() == 3) {
        op(v[1][0].first, v[1][0].second, v[1][1].first, v[1][1].second, v[1][2].first, v[1][2].second);
        for (auto i: v[1]) inv(i.first, i.second);
    }
    else if (v[1].size() == 2) {
        op(v[0][0].first, v[0][0].second, v[0][1].first, v[0][1].second, v[1][0].first, v[1][0].second);
        for (auto i: v[0]) inv(i.first, i.second);
        inv(v[1][0].first, v[1][0].second);
        
        op(v[0][0].first, v[0][0].second, v[0][1].first, v[0][1].second, v[1][1].first, v[1][1].second);
        for (auto i: v[0]) inv(i.first, i.second);
        inv(v[1][1].first, v[1][1].second);
        
    }
    else if (v[1].size() == 1) {
        op(v[1][0].first, v[1][0].second, v[0][0].first, v[0][0].second, v[0][1].first, v[0][1].second);
        inv(v[1][0].first, v[1][0].second); inv(v[0][0].first, v[0][0].second); inv(v[0][1].first, v[0][1].second);
        solve(x, y);
    }
    v[0].clear(); v[1].clear();
}

int main () {
    int T = read();
    while (T--) {
        int n = read(), m = read(), i, j;
        top = 0;
        for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
        if (n & 1) {
            for (i = 1; i < m; i++) {
                if (a[n][i] == '1' && a[n][i + 1] == '1') {
                    op(n - 1, i, n, i, n, i + 1);
                    inv(n - 1, i), inv(n, i), inv(n, i + 1);
                }
                else if (a[n][i] == '1') {
                    op(n - 1, i, n - 1, i + 1, n, i);
                    inv(n - 1, i), inv(n - 1, i + 1), inv(n, i);
                }
                else if (a[n][i + 1] == '1') {
                    op(n - 1, i, n - 1, i + 1, n, i + 1);
                    inv(n - 1, i), inv(n - 1, i + 1), inv(n, i + 1);
                }
            }
        }
        if (m & 1) {
            for (i = 1; i < n; i++) {
                if (a[i][m] == '1' && a[i + 1][m] == '1') {
                    op(i, m - 1, i, m, i + 1, m);
                    inv(i, m - 1), inv(i, m), inv(i + 1, m);
                }
                else if (a[i][m] == '1') {
                    op(i, m - 1, i + 1, m - 1, i, m);
                    inv(i, m - 1), inv(i + 1, m - 1), inv(i, m);
                }
                else if (a[i + 1][m] == '1') {
                    op(i, m - 1, i + 1, m - 1, i + 1, m);
                    inv(i, m - 1), inv(i + 1, m - 1), inv(i + 1, m);
                }
            }
        }
        for (i = 1; i <= (n >> 1); i++) for (j = 1; j <= (m >> 1); j++) solve((i << 1) - 1, (j << 1) - 1);
        cout << top << endl;
        for (i = 1; i <= top; i++) printf("%d %d %d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2, ans[i].x3, ans[i].y3);
    }
    return 0;
}