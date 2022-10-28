#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<long long> inv(100 + 1);
    inv[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 100 * inv[p[i]] % MOD * (dp[i - 1] + 1) % MOD;
    }
    cout << dp[n] << '\n';
}