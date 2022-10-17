#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 1001000;
int n, las[3][MAXN];
ll a[MAXN][2];

map <ll, int> vis[3];
map <int, int> f[MAXN];

int solve (int x, int y) {
    if (!x && !y) return 0;
    if (f[x].count(y)) return f[x][y];
    if (x == y) {
        f[x][y] = solve(x - 1, y - 1);
        if (las[2][x] != -1) f[x][y] = max(f[x][y], solve(las[2][x], las[2][x]) + 1);
        if (las[0][x] != -1) f[x][y] = max(f[x][y], solve(las[0][x], y) + 1);
        if (las[1][x] != -1) f[x][y] = max(f[x][y], solve(x, las[1][x]) + 1);
    }
    else if (x < y) {
        if (las[1][y] >= x) return f[x][y] = solve(x, las[1][y]) + 1;
        f[x][y] = solve(x, x);
        if (las[1][y] != -1) f[x][y] = max(f[x][y], solve(x, las[1][y]) + 1);
    }
    else {
        if (las[0][x] >= y) return f[x][y] = solve(las[0][x], y) + 1;
        f[x][y] = solve(y, y);
        if (las[0][x] != -1) f[x][y] = max(f[x][y], solve(las[0][x], y) + 1);
    }
    return f[x][y];
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i][0] = read() + a[i - 1][0];
    for (i = 1; i <= n; i++) a[i][1] = read() + a[i - 1][1];
    vis[0][0] = vis[1][0] = vis[2][0] = 0;
    las[0][0] = las[1][0] = las[2][0] = -1;
    for (i = 1; i <= n; i++) {
        if (!vis[0].count(a[i][0])) las[0][i] = -1; else las[0][i] = vis[0][a[i][0]];
        if (!vis[1].count(a[i][1])) las[1][i] = -1; else las[1][i] = vis[1][a[i][1]];
        if (!vis[2].count(a[i][0] + a[i][1])) las[2][i] = -1; else las[2][i] = vis[2][a[i][0] + a[i][1]];
        vis[0][a[i][0]] = i, vis[1][a[i][1]] = i, vis[2][a[i][0] + a[i][1]] = i;
		las[0][i] = max(las[0][i], las[0][i - 1]);
		las[1][i] = max(las[1][i], las[1][i - 1]);
		las[2][i] = max(las[2][i], las[2][i - 1]);
    }
    printf("%d\n", solve(n, n));
    return 0;
}