#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long MOD = 998244353;
long long fac[4000001], ifac[4000001];
long long dp[2000001];
long long h[2000001];

long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long ich(long long n, long long k) {
    return ifac[n] * fac[k] % MOD * fac[n - k] % MOD;
}

long long ch(long long n, long long k) {
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int main() {
    int n, m; cin >> n >> m;
    fac[0] = 1LL;
    for (int i = 1; i <= n + m; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    ifac[n + m] = inv(fac[n + m]);
    for (int i = n + m - 1; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
    dp[0] = 0;
    h[0] = 0;
    long long sum = 0LL;
    long long add = (n + m + 1) * inv(m + 1) % MOD;
    for (int l = 1; l <= n; l++) {
        dp[l] = add + ich(m + l, m) * sum % MOD;
        long long mult = (m + l) * inv(l) % MOD;
        dp[l] = dp[l] * mult % MOD;
        h[l] = dp[l] * ch(m - 1 + l, m - 1) % MOD;
        sum += h[l];
        sum %= MOD;
    }
    cout << dp[n] << "\n";
}