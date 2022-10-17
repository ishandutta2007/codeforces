#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 505;
int n, m;
char a[MAXN][MAXN];

int to[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int fa[MAXN * MAXN * 2], sel[MAXN * MAXN * 2], ans[MAXN * MAXN * 2];
int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }
int id (int x, int y) { return (x - 1) * m + y; }
void uni (int x, int y) { x = gf(x), y = gf(y); if (x != y) fa[x] = y; }

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n * m * 2; i++) fa[i] = i;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) if (a[i][j] == 'X') {
        int tmp = 0, p = 0, q = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + to[k][0], y = j + to[k][1];
            tmp += a[x][y] == '.';
            if (a[x][y] == '.') {
                if (!p) p = id(x, y);
                else if (!q) q = id(x, y);
            }
        }
        if (tmp & 1) { puts("NO"); return 0; }
        if (tmp) {
            uni(p, q + n * m), uni(p + n * m, q);
            if (tmp == 4) {
                p = id(i + to[2][0], j + to[2][1]);
                q = id(i + to[3][0], j + to[3][1]);
                uni(p, q + n * m), uni(p + n * m, q);
            }
        }
        ans[id(i, j)] = 5 * (tmp / 2 + 1);
    }
    for (i = 1; i <= n * m; i++) if (gf(i) == gf(i + n * m)) { puts("NO"); return 0; }
    puts("YES");
    for (i = 1; i <= n * m; i++) {
        if (ans[i]) { cout << ans[i] - 5 << ' '; if (i % m == 0) puts(""); continue; }
        if (sel[gf(i)]) { putchar(sel[gf(i)] == 1 ? '1' : '4'), sel[gf(i + n * m)] = 3 - sel[gf(i)]; }
        else if (sel[gf(i + n * m)]) { putchar(sel[gf(i + n * m)] == 1 ? '4' : '1'), sel[gf(i)] = 3 - sel[gf(i + n * m)]; }
        else sel[gf(i)] = 1, sel[gf(i + n * m)] = 2, putchar('1');
        cout << ' ';
        if (i % m == 0) puts("");
    }
    return 0;
}