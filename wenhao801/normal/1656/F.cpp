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
using ll = long long;

const int MAXN = 200200;
int n; ll a[MAXN];

ll calc (ll t) {
    ll ret = -1ll * (n - 1) * t * t; int i, j;
    for (i = 1; i <= n; i++) a[i] += t;
    if (a[n] <= 0) {
        for (i = 1; i < n; i++) ret += a[i] * a[n];
    }
    else if (a[1] >= 0) {
        for (i = 2; i <= n; i++) ret += a[1] * a[i];
    }
    else {
        for (i = 1; i <= n && a[i] < 0; i++) ret += a[i] * a[n];
        for (i = n; i >= 1 && a[i] > 0; i--) ret += a[1] * a[i];
        ret -= a[1] * a[n];
    }
    for (i = 1; i <= n; i++) a[i] -= t;
    return ret;
}

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        ll sum = 0;
        for (i = 1; i <= n; i++) a[i] = read(), sum += a[i];
        sort(a + 1, a + n + 1);
        if (1ll * (n - 2) * a[n] + sum < 0 || 1ll * (n - 2) * a[1] + sum > 0) { puts("INF"); continue; }
        ll L = -3e6, R = 3e6, ans = -1e18;
        while (L <= R) {
            ll mid = (L + R) >> 1, u = calc(mid), v = calc(mid + 1);
            ans = max(ans, max(u, v));
            if (u < v) L = mid + 1;
            else if (u > v) R = mid - 1;
            else break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}