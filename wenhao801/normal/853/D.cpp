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

const int MAXN = 300300, magic = 40;
using ll = long long;

const ll inf = 1e18;
void chkmin (ll &u, ll v) { u = min(u, v); }
int n;
ll f[MAXN][magic + 5], a[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read() / 100;
    for (i = 0; i <= n; i++) for (j = 0; j <= magic; j++) f[i][j] = inf;
    f[0][0] = 0;
    for (i = 0; i < n; i++) for (j = 0; j <= magic; j++) if (f[i][j] != inf) {
        if (j + a[i + 1] / 10 <= magic) chkmin(f[i + 1][j + a[i + 1] / 10], f[i][j] + a[i + 1]);
        chkmin(f[i + 1][max(0ll, j - a[i + 1])], f[i][j] + max(a[i + 1] - j, 0ll));
    }
    ll ans = inf;
    for (i = 0; i <= magic; i++) chkmin(ans, f[n][i]);
    printf("%lld\n", ans * 100);
    return 0;
}