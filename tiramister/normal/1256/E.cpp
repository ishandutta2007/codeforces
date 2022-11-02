#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<lint, int>> xs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i].first;
        xs[i].second = i;
    }
    std::sort(xs.begin(), xs.end());

    std::vector<std::pair<lint, int>> dp(n + 1, std::make_pair(INF, -1));
    dp[0] = std::make_pair(0, 0);

    for (int i = 0; i <= n; ++i) {
        lint min = INF, max = 0;
        for (int j = 1; j <= 5 && j <= i; ++j) {
            min = std::min(min, xs[i - j].first);
            max = std::max(max, xs[i - j].first);

            if (j >= 3) {
                auto cost = dp[i - j].first + (max - min);
                dp[i] = std::min(dp[i], std::make_pair(cost, i - j));
            }
        }
    }

    std::vector<int> seps;
    {
        int i = n;
        while (i > 0) {
            i = dp[i].second;
            seps.push_back(i);
        }
    }
    std::reverse(seps.begin(), seps.end());

    std::vector<int> ans(n, -1);
    int it = 0;
    for (int i = 0; i < n; ++i) {
        if (it < (int)seps.size() && i == seps[it]) ++it;
        ans[xs[i].second] = it;
    }

    std::cout << dp.back().first << " " << seps.size() << std::endl;
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}