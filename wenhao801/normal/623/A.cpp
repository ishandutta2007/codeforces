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

const int MAXN = 505;
int n, m; bool E[MAXN][MAXN]; int b[MAXN];
int fa[MAXN << 1];

int gf(int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }
void check (bool expr) { if (!expr) { puts("No"); exit(0); } }

int main () {
    n = read(), m = read(); int i, j, k;
    for (i = 1; i <= m; i++) { int u = read(), v = read(); E[u][v] = E[v][u] = 1; }
    if (m == n * (n - 1) / 2) { puts("Yes"); for (int i = 1; i <= n; i++) putchar('a'); putchar('\n'); return 0; }
    for (i = 1; i <= n * 2; i++) fa[i] = i;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) for (k = 1; k <= n; k++) if (i != j && i != k && j != k) {
        if (E[i][j] && E[j][k] && !E[i][k]) {
            check(b[i] != 1), check(b[k] != 1), check(b[j] != -1);
            b[i] = b[k] = -1, b[j] = 1;
            fa[gf(i)] = gf(k + n), fa[gf(k)] = gf(i + n);
        }
    }
    for (i = 1; i <= n; i++) if (!b[i]) b[i] = -1;
    for (i = 1; i <= n; i++) for (j = 1; j < i; j++) if (b[i] == -1 && b[j] == -1 && E[i][j])
        fa[gf(i)] = gf(j), fa[gf(i + n)] = gf(j + n);
    for (i = 1; i <= n; i++) check(gf(i) != gf(i + n));
    int cnt = 0, tmp[3] = {};
    for (i = 1; i <= n; i++) if (b[i] == -1) {
        for (j = 1; j <= cnt; j++) if (gf(i) == tmp[j]) break;
        if (j > cnt) tmp[++cnt] = gf(i);
        check(cnt <= 2);
    }
    check(cnt == 2);
    for (i = 1; i <= n; i++) if (b[i] == -1) {
        for (j = 1; j <= n; j++) if (i != j && b[j] == -1 && gf(i) == gf(j)) check(E[i][j]);
    }
    puts("Yes");
    for (i = 1; i <= n; i++) {
        if (b[i] == 1) putchar('b'); else putchar(gf(i) == tmp[1] ? 'a' : 'c');
    }
    putchar('\n');
    return 0;
}