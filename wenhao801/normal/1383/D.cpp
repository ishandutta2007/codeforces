#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 303;
int n, m, r[MAXN], c[MAXN], a[MAXN][MAXN];
bool visr[MAXN * MAXN], visc[MAXN * MAXN]; int ans[MAXN][MAXN];

#define pii pair<int, int>
#define fr first
#define se second
queue <pii> q;

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        a[i][j] = read();
        r[i] = max(r[i], a[i][j]), c[j] = max(c[j], a[i][j]);
    }
    for (i = 1; i <= n; i++) visr[r[i]] = 1;
    for (i = 1; i <= m; i++) visc[c[i]] = 1;
    int x = 0, y = 0;
    for (i = n * m; i >= 1; i--) {
        if (visr[i]) ++x; if (visc[i]) ++y;
        int nx, ny;
        if (visr[i] || visc[i]) nx = x, ny = y;
        else assert(!q.empty()), nx = q.front().fr, ny = q.front().se, q.pop();
        ans[nx][ny] = i;
        if (visr[i]) {
            for (j = y - 1; j >= 1; j--) q.push(make_pair(x, j));
        }
        if (visc[i]) {
            for (j = x - 1; j >= 1; j--) q.push(make_pair(j, y));
        }
    }
    for (i = 1; i <= n; i++, putchar('\n')) for (j = 1; j <= m; j++) printf("%d ", ans[i][j]);
    return 0;
}