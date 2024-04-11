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

const int MAXN = 55;

int a[MAXN][MAXN], b[MAXN][MAXN];
int step[MAXN * MAXN][10];
int cnt = 0;

int n, m;

int main () {
    n = read(), m = read();
    int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) a[i][j] = read();
    for (i = 1; i < n; i++)
        for (j = 1; j < m; j++) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
                b[i][j] = b[i + 1][j] = b[i + 1][j + 1] = b[i][j + 1] = 1, step[++cnt][1] = i, step[cnt][2] = j;
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) if (a[i][j] != b[i][j]) { puts("-1"); return 0; }
    printf("%d\n", cnt);
    for (i = 1; i <= cnt; i++) printf("%d %d\n", step[i][1], step[i][2]);
    return 0;
}