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

const int inf = 1e9 + 7;
int n;
struct gem { bool op; int r, b; } a[22];
int f[16 * 16 + 1][1 << 16];

int main () {
    n = read(); int i, j, sr = 0, sb = 0;
    for (i = 0; i < n; i++) {
        char op[3]; scanf("%s", op);
        a[i].op = op[0] == 'B'; a[i].r = read(), a[i].b = read();
        sr += a[i].r, sb += a[i].b;
    }
    for (i = 0; i <= n * n; i++) for (j = 0; j < (1 << n); j++) f[i][j] = -inf;
    f[0][0] = 0;
    for (i = 0; i < (1 << n); i++) {
        int r = 0, b = 0;
        for (j = 0; j < n; j++) if ((i >> j) & 1) r += a[j].op == 0, b += a[j].op == 1;
        for (j = 0; j <= n * n; j++) if (f[j][i] != -inf) {
            for (int k = 0; k < n; k++) if (!((i >> k) & 1)) {
                int dr = min(a[k].r, r), db = min(a[k].b, b);
                f[j + dr][i | (1 << k)] = max(f[j + dr][i | (1 << k)], f[j][i] + db);
            }
        }
    }
    int ans = inf;
    for (i = 0; i <= n * n; i++) if (f[i][(1 << n) - 1] != -inf)
        ans = min(ans, n + max(sr - i, sb - f[i][(1 << n) - 1]));
    printf("%d\n", ans);
    return 0;
}