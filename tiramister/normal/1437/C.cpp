#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1 << 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ts(n);
    for (auto& t : ts) std::cin >> t;
    std::sort(ts.begin(), ts.end());

    int m = n * 2 + 1;
    std::vector<int> dp(m, 0);  // i
    for (auto t : ts) {
        for (int i = m - 1; i > 0; --i) {
            dp[i] = dp[i - 1] + std::abs(t - i);
        }

        dp[0] = INF;
        for (int i = 1; i < m; ++i) {
            dp[i] = std::min(dp[i], dp[i - 1]);
        }
    }

    std::cout << dp.back() << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}