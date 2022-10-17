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

const int MAXN = 2020, mod = 1e9 + 7;
struct BIT {
    int t[MAXN];
    inline int lowbit (int x) { return x & -x; }
    inline int ask (int x) { int ret = 0; while (x) ret = (ret + t[x]) % mod, x -= lowbit(x); return ret; }
    inline void add (int x, int k) { while (x <= 2000) t[x] = (t[x] + k) % mod, x += lowbit(x); }
    inline void modify (int l, int r, int k) { if (l <= r) add(l, k), add(r + 1, -k); }
} r[MAXN], c[MAXN];

int n, m, sufr[MAXN][MAXN], sufc[MAXN][MAXN], f[MAXN][MAXN][2]; char a[MAXN][MAXN];

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    if (n == 1 && m == 1) { if (a[1][1] == 'R') puts("0"); else puts("1"); return 0; }
    for (i = n; i >= 1; i--) for (j = m; j >= 1; j--) sufr[i][j] = sufr[i][j + 1] + (a[i][j] == 'R'), sufc[i][j] = sufc[i + 1][j] + (a[i][j] == 'R');
    f[0][1][0] = f[1][0][1] = 1; r[1].modify(2, m - sufr[1][1], 1), c[1].modify(2, n - sufc[1][1], 1);
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        f[i][j][0] = r[i].ask(j); f[i][j][1] = c[j].ask(i);
        // printf("f %d %d: %d %d\n", i, j, f[i][j][0], f[i][j][1]);
        c[j].modify(i + 1, n - sufc[i + 1][j], f[i][j][0]); r[i].modify(j + 1, m - sufr[i][j + 1], f[i][j][1]);
    }
    cout << ((f[n][m][0] + f[n][m][1]) % mod + mod) % mod << endl;
    return 0;
}