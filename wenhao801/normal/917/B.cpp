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

#define pii pair<int, int>
#define fr first
#define se second

int n, m; const int MAXN = 110;
vector <pii> E[MAXN];

int f[MAXN][MAXN][26][2];

int dfs (int x, int y, int c, int now) {
    if (f[x][y][c][now]) return f[x][y][c][now];
    bool win = 0;
    if (now) {
        for (auto i: E[x]) if (i.se >= c) win |= dfs(i.fr, y, i.se, now ^ 1) == -1;
    }
    else {
        for (auto i: E[y]) if (i.se >=c ) win |= dfs(x, i.fr, i.se, now ^ 1) == -1;
    }
    f[x][y][c][now] = win ? 1 : -1; return f[x][y][c][now];
}

int main () {
    n = read(), m = read(); int i, j;
    while (m--) {
        int u = read(), v = read(); char str[5]; scanf("%s", str);
        E[u].push_back(make_pair(v, str[0] - 'a'));
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) putchar(dfs(i,j , 0, 1) == 1 ? 'A' : 'B');
        puts("");
    }
    return 0;
}