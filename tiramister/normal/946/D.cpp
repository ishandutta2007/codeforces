#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1 << 30;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<int> ts;
        for (int t = 0; t < m; ++t) {
            char c;
            std::cin >> c;
            if (c == '1') ts.push_back(t);
        }
        int sz = ts.size();

        std::vector<int> ndp(k + 1, INF);
        for (int l = 0; l <= sz; ++l) {
            // take l lessons
            int cost = INF;
            if (l == 0) {
                cost = 0;
            } else {
                for (int s = 0; s + l - 1 < sz; ++s) {
                    cost = std::min(cost, ts[s + l - 1] - ts[s] + 1);
                }
            }

            // skip s lessons
            int s = sz - l;
            for (int j = 0; j + s <= k; ++j) {
                ndp[j + s] = std::min(ndp[j + s], dp[j] + cost);
            }
        }

        dp = ndp;
    }

    std::cout << *std::min_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}