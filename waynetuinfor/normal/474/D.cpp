#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
long long dp[2][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, k; cin >> t >> k;
    dp[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1]; dp[0][i] %= mod;
        if (i - k >= 0) dp[1][i] = dp[1][i - k] + dp[0][i - k], dp[1][i] %= mod;
    }
    for (int i = 0; i < maxn; ++i) dp[0][i] += dp[1][i], dp[0][i] %= mod;
    for (int i = 1; i < maxn; ++i) dp[0][i] += dp[0][i - 1], dp[0][i] %= mod;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << (((dp[0][b] - dp[0][a - 1]) % mod) + mod) % mod << endl;
    }
    return 0;
}