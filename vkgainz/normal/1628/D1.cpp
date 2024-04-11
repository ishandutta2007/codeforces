#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <iomanip>
#include <chrono>
 
using namespace std;
 
double dp[2001][2001];
long long dpMod[2001][2001];
long long M = 1e9 + 7;
long long inv2 = (M + 1) / 2;

long long solve(int n, int m, int k) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                if (j == 0) dp[i][j] = 0, dpMod[i][j] = 0 ;
                else {
                    dp[i][j] = 1e15;
                    dpMod[i][j] = 0;
                } 
            } else {
                if (j == 0) {
                    dp[i][j] = 0, dpMod[i][j] = 0;
                } else {
                    if (dp[i - 1][j] > dp[i - 1][j - 1]) {
                        double dif = (dp[i - 1][j] - dp[i - 1][j - 1]) * 1.0 / 2;
                        if (dif > k) {
                            dp[i][j] = dp[i - 1][j - 1] + k;
                            dpMod[i][j] = (dpMod[i - 1][j - 1] + k) % M;
                        } else {
                            //take avg
                            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * 1.0 / 2;
                            dpMod[i][j] = (dpMod[i - 1][j] + dpMod[i - 1][j - 1]) * inv2 % M;
                        }
                    } else {
                        dp[i][j] = dp[i - 1][j];
                        dpMod[i][j] = dpMod[i - 1][j];
                    }
                }
            }
        }
    }
    return dpMod[n][m];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        long long ans = solve(n, m, k);
        ans %= M;
        if (ans < 0) ans += M;
        cout << ans << "\n";
    }
}