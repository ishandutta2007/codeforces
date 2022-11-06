#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

const int maxn = 1e6 + 5;
int b[maxn];

int main() {
    int n, m, a; scanf("%d%d%d", &n, &m, &a);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    int ans = 1;
    for (int i = 1; i <= m; ++i) {
        int way = fpow(a, 2 * (b[i] - b[i - 1])) % mod;
        (way += mod - fpow(a, b[i] - b[i - 1])) %= mod;
        way = way * 1ll * fpow(2, mod - 2) % mod;
        (way += fpow(a, b[i] - b[i - 1])) %= mod;
        ans = ans * 1ll * way % mod;
    }
    ans = ans * 1ll * fpow(a, n - b[m] - b[m]) % mod;
    printf("%d\n", ans);
    return 0;
}