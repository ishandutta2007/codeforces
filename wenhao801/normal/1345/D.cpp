#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

char a[1010][1010];
int n, m;
bool v[1010][1010];

void dfs (int x, int y) {
    if (a[x][y] == '.') return;
    if (x < 0 || x > n || y < 0 || y > m) return;
    if (v[x][y]) return;
    v[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

bool awr[1010], awc[1010];

int main () {
    n = read(), m = read();
    int i, j;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (i = 0; i <= n; i++) a[i][0] = '.';
    for (i = 0; i <= m; i++) a[0][i] = '.';
    for (i = 1; i <= n; i++) {
        int f = 0;
        bool aw = true;
        for (j = 1; j <= m; j++) {
            if (a[i][j] == '#') aw = false;
            if (a[i][j] != a[i][j - 1]) f++;
            if (f == 3) { puts("-1"); return 0; }
        }
        if (aw) awr[i] = true;
    }
    for (i = 1; i <= m; i++) {
        int f = 0; bool aw = true;
        for (j = 1; j <= n; j++) {
            if (a[j][i] == '#') aw = false;
            if (a[j][i] != a[j - 1][i]) f++;
            if (f == 3) { puts("-1"); return 0; }
        }
        if (aw) awc[i] = true;
    }
    for (i = 1; i <= n; i++) {
        if (!awr[i]) continue;
        for (j = 1; j <= m; j++) if (awc[j]) break;
        if (j == m + 1) { puts("-1"); return 0; }
    }
    for (i = 1; i <= m; i++) {
        if (!awc[i]) continue;
        for (j = 1; j <= n; j++) if (awr[j]) break;
        if (j == n + 1) { puts("-1"); return 0; }
    }
    int ans = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++)
        if (a[i][j] == '#' && !v[i][j]) ans++, dfs(i, j);
    cout << ans << endl;
    return 0;
}