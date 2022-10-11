#include <iostream>

typedef long long ll;

const int MOD = 1e9 + 7;

int a[2020];
int dp[2020][2020];

int main() {
    int n, h;
    std::cin >> n >> h;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if(a[i] > h) {
            std::cout << "0\n";
            return 0;
        }
        int need = h - a[i];
        dp[i][need] = dp[i - 1][need] + (ll)dp[i - 1][need + 1] * (need + 1) % MOD;
        if(need > 0) {
            dp[i][need] += (ll) dp[i - 1][need] * need % MOD;
            dp[i][need] += (ll) dp[i - 1][need - 1] % MOD;
        }
        dp[i][need] %= MOD;
    }
    std::cout << dp[n][0] + dp[n][1] << '\n';
}