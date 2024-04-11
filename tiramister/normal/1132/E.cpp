#include <iostream>
#include <vector>

using lint = long long;

constexpr lint N = 100;
constexpr lint M = N * 36;

void solve() {
    lint w;
    std::cin >> w;

    std::vector<lint> xs(8);
    for (auto& x : xs) std::cin >> x;
    xs.insert(xs.begin(), 0);

    std::vector<bool> dp(M + 1, false);
    dp[0] = true;

    for (int i = 1; i <= 8; ++i) {
        auto x = std::min(xs[i], N);
        xs[i] -= x;

        while (x--) {
            for (lint j = M; j >= i; --j) {
                if (dp[j - i]) dp[j] = true;
            }
        }
    }

    lint ans = 0;
    for (lint sw = 0; sw <= std::min(M, w); ++sw) {
        if (!dp[sw]) continue;

        lint pw = sw;
        for (lint i = 8; i >= 1; --i) {
            pw += std::min((w - pw) / i, xs[i]) * i;
        }

        ans = std::max(ans, pw);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}