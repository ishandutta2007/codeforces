#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
int a[maxn], fac[maxn], invfac[maxn];

int fpow(int, int);
int c(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int m = (n % 2 == 1 && n % 4 != 3 ? n + 1 : n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    fac[0] = 1; invfac[0] = 1;
    for (int i = 1; i < maxn; ++i) fac[i] = (long long)fac[i - 1] * (long long)i % mod, invfac[i] = fpow(fac[i], mod - 2);
    if (n % 4 == 0) {
        int ans = 0;
        for (int i = 0, cnt = -1; i < n; ++i) {
            if (i % 2 == 0) ++cnt;
            if (i % 2 == 0) ans = (ans + (long long)a[i] * (long long)c((m - 2) >> 1, cnt) % mod) % mod;
            else ans = (ans - (long long)a[i] * (long long)c((m - 2) >> 1, cnt) % mod) % mod;
        }
        while (ans < 0) ans += mod;
        cout << ans << endl;
    }
    if (n % 4 == 1) {
        int ans = 0;
        for (int i = 0, cnt = -1; i < n; ++i) {
            if (i % 2 == 0) ++cnt;
            if (i % 2 == 0) ans = (ans + (long long)a[i] * (long long)c((m - 2) >> 1, cnt) % mod) % mod;
        }
        while (ans < 0) ans += mod;
        cout << ans << endl;
    }
    if (n % 4 == 2) {
        int ans = 0;
        for (int i = 0, cnt = -1; i < n; ++i) {
            if (i % 2 == 0) ++cnt;
            ans = (ans + (long long)a[i] * (long long)c((m - 2) >> 1, cnt) % mod) % mod;
        }
        while (ans < 0) ans += mod;
        cout << ans << endl;
    }
    if (n % 4 == 3) {
        int ans = 0;
        // while (m % 3 != 0) ++m;
        int coef = (long long)c((m - 3) >> 1, 0) % mod;
        coef = ((coef) % mod) % mod;
        ans = (ans + (long long)a[0] * (long long)coef % mod) % mod;
        coef = (long long)c((m - 3) >> 1, 0) % mod;
        coef = ((coef * 2) % mod) % mod;
        ans = (ans + (long long)a[1] * (long long)coef % mod) % mod;
        for (int i = 2, cnt = 0; i < n; ++i) {
            if (i % 2 == 0) ++cnt;
            if (i % 2 == 0) {
                int coef = (long long)c((m - 3) >> 1, cnt) - (long long)c((m - 3) >> 1, cnt - 1) % mod;
                coef = ((coef % mod) + mod) % mod;
                ans = (ans + (long long)a[i] * (long long)coef % mod) % mod;
            } else {
                int coef = (long long)c((m - 3) >> 1, cnt) % mod;
                coef = ((coef * 2) % mod) % mod;
                ans = (ans + (long long)a[i] * (long long)coef % mod) % mod;
            }
        }
        while (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return 0;
}

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = (long long)ret * (long long)a % mod;
        a = (long long)a * (long long)a % mod;
    }
    return ret;
}

int c(int n, int k) {
    // cout << "C(" << n << ", " << k << ")" << endl;
    return ((long long)fac[n] * (long long)invfac[k] % mod * (long long)invfac[n - k]) % mod;
}