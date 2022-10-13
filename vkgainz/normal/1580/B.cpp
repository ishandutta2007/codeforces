#include <iostream>
#include <vector>
#include <algorithm>

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

using namespace std;

long long dp[101][101][101];
long long choose[101][101];
long long fac[101];

int main() {
    int n, m, x;
    long long MOD;
    cin >> n >> m >> x >> MOD;
    if (x > (n + 3) / 2) {
        cout << 0 << "\n";
        return 0;
    }
    fac[0] = 1LL;
    for (int k = 0; k <= 100; k++) {
        dp[0][0][k] = 1;
        choose[0][k] = 0;
        choose[k][0] = 1;
        if (k > 0) fac[k] = fac[k - 1] * 1LL * k % MOD;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
            choose[i][j] %= MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min((i + 3) / 2, x); j++) {
            bool ge = false;
            for (int k = 0; k <= m; k++) {
                if (k == 0) {
                    if (j == 0) {
                        dp[i][j][k] = 1;
                    }
                    continue;
                }
                if (k == 1) {
                    if (j == 1) {
                        dp[i][j][k] = fac[i];
                    }
                    continue;
                }
                if (k > i) {
                    if (j == 0) {
                        dp[i][j][k] = fac[i];
                    }
                    continue;
                }
                for (int pos = 1; pos <= i; pos++) {
                    for (int y = 0; y <= j; y++) {
                       if (y <= (pos - 1 + 3) / 2 and (j - y) <= (i - pos + 3) / 2) {
                           dp[i][j][k] +=
                               (dp[pos - 1][y][k - 1] * dp[i - pos][j - y][k - 1]) % MOD
                               * choose[i - 1][pos - 1] % MOD;
                           dp[i][j][k] %= MOD;
                       }
                    }
                }
                if (dp[i][j][k] != 0 and not ge) {
                    ge = true;
                }
                if (ge and dp[i][j][k] == 0 and MOD >= 20000) {
                    break;
                }
            }
        }
    }
    if (dp[n][x][m] < 0) dp[n][x][m] += MOD;
    cout << dp[n][x][m] << "\n";
}