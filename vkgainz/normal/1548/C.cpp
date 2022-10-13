#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e9 + 7;
vector<long long> fac(3000005), invfac(3000005);

//1 / x % MOD = x^(MOD - 2) % MOD

long long inv(int b, int p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

long long choose(int n, int k) {
    if (n < k) return 0LL;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> dp(3 * n + 1);
    dp[0] = n + 1;
    dp[1] = 3 * n * 1LL * (n + 1) / 2 % MOD;
    fac[0] = 1LL;
    for (int i = 1; i <= 3 * n + 3; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[3 * n + 3] = inv(fac[3 * n + 3]);
    //inv(1 / x!) = inv(1 / (x + 1)! * (x + 1))
    for (int i = 3 * n + 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
    long long denom = inv(3);
    for (int i = 2; i <= 3 * n; i++) {
        dp[i] = (choose(3 * n + 3, i + 1) - 3 * dp[i - 1] - dp[i - 2]) % MOD * denom % MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }

    while (q--) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
}