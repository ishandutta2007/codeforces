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

#define ll long long
const int MAXN = 505;
const ll inf = 1e18;

inline void chkmin (ll &x, ll y) { x = min(x, y); }
inline void chkmax (ll &x, ll y) { x = max(x, y); }

int n, K, a[MAXN], b[MAXN];
ll f[MAXN][MAXN], sa[MAXN], sb[MAXN];

int main () {
    n = read(), K = read(); int i, j, k;
    for (i = 1; i <= n; i++) a[i] = read(), b[i] = read(), sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
    for (i = 0; i <= n; i++) for (j = 0; j < K; j++) f[i][j] = -1;
    f[0][0] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < K; j++) if (f[i][j] != -1) {
            int tmp = (sa[i] + sb[i] - j) % K;
            for (k = 0; k < K; k++) {
                int tmp2 = (sa[i + 1] + sb[i + 1] - k) % K;
                if (a[i + 1] >= (k - j + K) % K && b[i + 1] >= (tmp2 - tmp + K) % K)
                    chkmax(f[i + 1][k], f[i][j] + (tmp2 < tmp) + (k < j) + (a[i + 1] + b[i + 1] - (k - j + K) % K - (tmp2 - tmp + K) % K) / K);
            }
        }
    }
    ll ans = 0;
    for (i = 0; i < K; i++) chkmax(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}