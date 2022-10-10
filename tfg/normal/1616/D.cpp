#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int x;
        std::cin >> x;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(4, -1e9));
        dp[0][0] = 0;
        for(int i = 0; i < n; i++) for(int j = 0, sum = 0; i-j >= 0 && j < 4; j++) {
            sum += a[i-j] - x;
            //std::cout << "at [" << i-j << ", " << i << "] got " << sum << '\n';
            //std::cout << "dp(" << i << ", " << j << ") = " << dp[i][j] << '\n';
            if(dp[i][j] >= 0 && (sum >= 0 || j == 0)) {
                dp[i+1][std::min(j+1, 3)] = std::max(dp[i+1][std::min(j+1, 3)], dp[i][j]+1);
            } else if(sum < 0 && j >= 1) {
                sum = -1e9;
            }
            dp[i+1][0] = std::max(dp[i+1][0], dp[i][j]);
        }
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            ans = std::max(ans, dp[n][i]);
        }
        std::cout << ans << '\n';
    }
}