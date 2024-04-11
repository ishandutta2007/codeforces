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

const int MAXN = 4040, shift = 2000;
const int mod = 1e9 + 7, inv2 = (mod + 1) >> 1;

int n; char a[MAXN], b[MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];

#define f(i, j) f[i][(j) + shift]
#define g(i, j) g[i][(j) + shift]
inline void add (int &u, int v) { u += v; if (u >= mod) u -= mod; }
inline void dec (int &u, int v) { u -= v; if (u < 0) u += mod; }

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j, ans = 0;
        scanf("%s", a + 1); scanf("%s", b + 1);
        for (i = 2; i <= n; i += 2) {
            if (a[i] != '?') a[i] ^= 1;
            if (b[i] != '?') b[i] ^= 1;
        }
        f(0, 0) = 1;
        for (i = 1; i <= n; i++) for (j = -shift; j <= shift; j++) {
            if (a[i] != '1' && b[i] != '1') add(f(i, j), f(i - 1, j));
            if (a[i] != '1' && b[i] != '0') add(f(i, j - 1), f(i - 1, j));
            if (a[i] != '0' && b[i] != '1') add(f(i, j + 1), f(i - 1, j));
            if (a[i] != '0' && b[i] != '0') add(f(i, j), f(i - 1, j));
        }
        g(n + 1, 0) = 1;
        for (i = n; i >= 1; i--) for (j = -shift; j <= shift; j++) {
            if (a[i] != '1' && b[i] != '1') add(g(i, j), g(i + 1, j));
            if (a[i] != '1' && b[i] != '0') add(g(i, j - 1), g(i + 1, j));
            if (a[i] != '0' && b[i] != '1') add(g(i, j + 1), g(i + 1, j));
            if (a[i] != '0' && b[i] != '0') add(g(i, j), g(i + 1, j));
        }
        for (i = 1; i <= n; i++) {
            if (a[i] != '0' && b[i] != '1') {
                int tmp = 0;
                for (j = -shift; j < 0; j++) add(tmp, 1ll * f(i - 1, j) * g(i + 1, -j - 1) % mod);
                for (j = 0; j <= shift; j++) dec(tmp, 1ll * f(i - 1, j) * g(i + 1, -j - 1) % mod);
                add(ans, 1ll * tmp * i % mod);
            }
            if (a[i] != '1' && b[i] != '0') {
                int tmp = 0;
                for (j = 1; j <= shift; j++) add(tmp, 1ll * f(i - 1, j) * g(i + 1, 1 - j) % mod);
                for (j = -shift; j <= 0; j++) dec(tmp, 1ll * f(i - 1, j) * g(i + 1, 1 - j) % mod);
                add(ans, 1ll * tmp * i % mod);
            }
        }
        printf("%d\n", ans);
        for (i = 0; i <= n + 1; i++) for (j = -shift - 1; j <= shift + 1; j++) f(i, j) = g(i, j) = 0;
    }
    return 0;
}