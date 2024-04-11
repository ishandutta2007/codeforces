#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10, mod = 1e9 + 7;
int fac[maxn], invfac[maxn];

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = (long long)ret * (long long)a % mod;
        a = (long long)a * (long long)a % mod;
    }
    return ret;
}

void init() {
    fac[0] = 1; fac[1] = 1;
    for (int i = 2; i < maxn; ++i) fac[i] = (long long)fac[i - 1] * (long long)i % mod;
    for (int i = 0; i < maxn; ++i) invfac[i] = fpow(fac[i], mod - 2);
}

int add(int a, int b) {
    return a + b >= mod ? (a + b) % mod : a + b;
}

int sub(int a, int b) {
    int c = a - b;
    return c < 0 ? c + mod : c;
}

int mul(int a, int b) {
    long long c = (long long)a * (long long)b;
    return c >= mod ? c % mod : c;
}

int c(int n, int k) {
    if (k > n) return 0;
    return mul(mul(fac[n], invfac[k]), invfac[n - k]);
}

int main() {
    init();
    int n; cin >> n;
    int ans = 1, p = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int cnk = c(i, n) * 2 % mod;
        int pre = add(add(ans, cnk), mul(sub(sub(ans, p), cnk), 2));
        pre %= mod;
        p = ans; ans = pre;
    }
    cout << ans << endl;
    return 0;
}