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

const int MAXN = 200200;
using ll = long long;
int a[MAXN];

int main () {
    int T = read(); while (T--) {
        int n = read(), m = read(), i, j; ll s = 0, ans = 0;
        for (i = 1; i <= n; i++) a[i] = read(), ans += a[i], a[i] -= (n - i);
        sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
        for (i = 1; i <= m; i++) ans -= a[i];
        ans -= 1ll * (m - 1) * m / 2;
        printf("%lld\n", ans);
    }
    return 0;
}