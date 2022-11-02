#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1 << 30;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i];
        xs[i] -= i;
    }
    std::vector<int> bs(m);
    for (auto& b : bs) std::cin >> b;

    xs.insert(xs.begin(), -INF);
    xs.push_back(INF);
    bs.insert(bs.begin(), 0);
    bs.push_back(n + 1);
    n = xs.size(), m = bs.size();

    int ans = 0;
    for (int i = 0; i + 1 < m; ++i) {
        int l = bs[i], r = bs[i + 1];

        if (xs[l] > xs[r]) {
            std::cout << "-1\n";
            return;
        }

        int len = r - l - 1;
        std::vector<int> dp(len + 1, INF);
        dp[0] = -INF;

        for (int j = l + 1; j < r; ++j) {
            auto x = xs[j];
            if (x < xs[l] || xs[r] < x) continue;
            *std::upper_bound(dp.begin(), dp.end(), x) = x;
        }

        for (int j = len; j >= 0; --j) {
            if (dp[j] < INF) {
                ans += len - j;
                break;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}