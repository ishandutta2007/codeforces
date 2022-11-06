#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, maxv = 1e6 + 10, mod = 1e9 + 7;
int a[maxn];
long long fac[maxn], invfac[maxn];
long long ans[maxv], cnt[maxv], cal[maxv];

long long fpow(long long a, int n) {
    long long ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

long long c(int n, int k) {
    return fac[n] * invfac[n - k] % mod * invfac[k] % mod;
}

void init() {
    fac[1] = 1;
    for (int i = 2; i < maxn; ++i) fac[i] = fac[i - 1] * (long long)i % mod;
    invfac[1] = fpow(fac[1], mod - 2);
    for (int i = 2; i < maxn; ++i) invfac[i] = fpow(fac[i], mod - 2);
    for (int i = 1; i <= 1000000; ++i) cal[i] = i * fpow(2, i - 1) % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    init();
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= sqrt(a[i]); ++j) if (a[i] % j == 0) {
            if (j == sqrt(a[i])) ++cnt[j];
            else ++cnt[j], ++cnt[a[i] / j];
        }
    }
    for (int i = 1000000; i >= 2; --i) {
        ans[i] = cal[cnt[i]];
        for (int j = 2; i * j <= 1000000; ++j) ans[i] = ((ans[i] - ans[i * j]) + mod) % mod;
    }
    long long s = 0;
    for (int i = 2; i <= 1000000; ++i) s = (s + (long long)i * ans[i] % mod) % mod;
    cout << s << endl;
    return 0;
}