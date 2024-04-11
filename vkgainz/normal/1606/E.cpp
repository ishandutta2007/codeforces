#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
using namespace std;

long long choose[501][501];
long long dp[501][501];
long long tpow[501][501];
long long MOD = 998244353;

int main() {
    int n, x; cin >> n >> x;
    for (int i = 0; i <= 500; i++) {
        choose[0][i] = 0;
        choose[i][0] = 1;
    }
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            choose[i][j] %= MOD;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        tpow[i][0] = 1LL;
        for (int j = 1; j <= 500; j++) {
            tpow[i][j] = tpow[i][j - 1] * i % MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = tpow[j][i] - tpow[j - 1][i];
            dp[i][j] %= MOD;
        }
        for (int j = i; j <= x; j++) {
            for (int k = 0; k <= i - 1; k++) {
                dp[i][j] += choose[i][k] * 1LL * tpow[i - 1][k] % MOD * 1LL * dp[i - k][j - (i - 1)] % MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    long long ans = 0LL;
    for (int i = 1; i <= x; i++) {
        ans += dp[n][i];
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}