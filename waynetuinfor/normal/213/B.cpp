#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, mod = 1e9 + 7;
int dp[maxn], a[10], fac[maxn], invfac[maxn];

int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
int mul(int a, int b) { return a * 1LL * b < mod ? a * 1LL * b : a * 1LL * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

void init() {
    fac[1] = 1; invfac[0] = 1; fac[0] = 1;
    for (int i = 2; i < maxn; ++i) fac[i] = mul(fac[i - 1], i);
    for (int i = 1; i < maxn; ++i) invfac[i] = fpow(fac[i], mod - 2);
}

int c(int n, int k) {
    if (k > n) return 0;
    return mul(mul(fac[n], invfac[k]), invfac[n - k]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n; cin >> n;
    for (int i = 0; i < 10; ++i) cin >> a[i];
    dp[0] = 1;
    int cur = 0;
    for (int i = 1; i <= 9; ++i) {
        cur += a[i];
        for (int j = n; j >= cur; --j) {
            int d = 0;
            for (int k = a[i]; k <= j; ++k) {
                d = add(d, mul(c(j, k), dp[j - k]));
                // cout << "j = " << j << " k = " << k << " d = " << d << endl;
            }        
            // cout << "dp[" << j << "] = " << dp[j] << endl;
            dp[j] = d;
        }
        for (int j = 0; j < cur; ++j) dp[j] = 0;
    }
    // for (int i = 0; i <= n; ++i) cout << dp[i] << ' '; cout << endl;
    cur += a[0];
    int ans = 0;
    for (int j = n; j >= cur; --j) {
        int d = 0;
        for (int k = a[0]; k <= j; ++k) {
            d = add(d, mul(c(j - 1, k), dp[j - k]));
            // cout << "j = " << j << " k = " << k << " d = " << d << endl;
            // cout << "c = " << c(j - 1, k) << endl;
        }
        ans = add(ans, d);
    }
    cout << ans << endl;
    return 0;
}