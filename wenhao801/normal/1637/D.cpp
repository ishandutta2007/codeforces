#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 110;
const ll inf = 1e18;
int n, a[MAXN], b[MAXN], sa[MAXN], sb[MAXN];
ll f[2][MAXN * MAXN * 2];

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j; ll ans = 0;
        for (i = 1; i <= n; i++) a[i] = read(), sa[i] = a[i] + sa[i -1], ans += 1ll * (n - 1) * a[i] * a[i];
        for (i = 1; i <= n; i++) b[i] = read(), sb[i] = b[i] + sb[i - 1], ans += 1ll * (n - 1) * b[i] * b[i];
        for (i = 0; i <= n * 200; i++) f[0][i] = f[1][i] = inf;
        f[0][0] = 0;
        for (i = 1; i <= n; i++) {
            const int now = i & 1, las = now ^ 1;
            for (j = 0; j <= i * 200; j++) f[now][j] = inf;
            for (j = 0; j <= (i - 1) * 200; j++) if (f[las][j] != inf) {
                int Sa = j, Sb = sa[i - 1] + sb[i - 1] - Sa;
                f[now][Sa + a[i]] = min(f[now][Sa + a[i]], f[las][j] + Sa * a[i] + Sb * b[i]);
                f[now][Sa + b[i]] = min(f[now][Sa + b[i]], f[las][j] + Sa * b[i] + Sb * a[i]);
            }
        }
        ll tmp = 1e18;
        for (i = 0; i <= n * 200; i++) tmp = min(tmp, f[n & 1][i]);
        printf("%lld\n", ans + tmp *2);
    }
    return 0;
}