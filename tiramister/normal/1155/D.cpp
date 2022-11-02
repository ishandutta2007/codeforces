#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<lint> dp(5, 0);
    while (n--) {
        lint a;
        std::cin >> a;

        dp[1] += a;
        dp[2] += a * x;
        dp[3] += a;

        for (int i = 1; i < 5; ++i) {
            dp[i] = std::max(dp[i], dp[i - 1]);
        }
    }

    std::cout << dp[4] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}