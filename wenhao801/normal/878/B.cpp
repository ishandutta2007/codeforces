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

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 500500;
#define ll long long
#define int long long

int n, K, m; ll ans;
pii a[MAXN], b[MAXN]; int top;

signed main () {
    n = read(), K = read(), m = read();
    int cur = 0, cnt = 0, i, j;
    ans = 1ll * n * m;
    for (i = 1; i <= n; i++) {
        int x = read();
        if (x == a[top].fr) {
            ++a[top].se;
            if (a[top].se == K) --top, ans -= 1ll * m * K;
        }
        else a[++top] = make_pair(x, 1);
    }
    ll O = ans / m;
    if (cnt) a[++top] = make_pair(cur, cnt);
    if (!top) { printf("%lld\n", ans); return 0; }
    if (top == 1) { ans -= 1ll * m * a[1].se / K * K; printf("%lld\n", ans); return 0; }
    if (m == 1) { printf("%lld\n", ans); return 0; }
    int l = 1, r = top;
    while (l <= r) {
        if (a[l].fr != a[r].fr) {
            printf("%lld\n", ans);
            return 0;
        }
        if (l != r && a[l].se + a[r].se < K) { printf("%lld\n", ans); return 0; }
        if (l == r) {
            if (1ll * m * a[l].se % K == 0) { puts("0"); return 0; }
            ans -= 1ll * m * a[l].se / K * K;
            printf("%lld\n", ans);
            return 0;
        }
        if (l >= r - 1 && a[l].se + a[r].se == K) {
            if (m & 1) printf("%lld\n", O);
            else puts("0");
            return 0;
        }
        if (a[l].se + a[r].se > K) {
            printf("%lld\n", ans - 1ll * (m - 1) * K);
            return 0;
        }
        ans -= 1ll * (m - 1) * K;
        ++l, --r;
    }
    printf("%lld\n", ans);
    return 0;
}