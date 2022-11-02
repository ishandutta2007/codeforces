#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1 << 30;

void solve() {
    int n, h, l, r;
    std::cin >> n >> h >> l >> r;

    std::vector<int> dp(h, -INF);
    auto ndp = dp;
    dp[0] = 0;

    while (n--) {
        int t;
        std::cin >> t;

        std::fill(ndp.begin(), ndp.end(), -INF);
        for (int pt = 0; pt < h; ++pt) {
            int nt = (pt + t) % h;
            ndp[nt] = std::max(ndp[nt], dp[pt] + (l <= nt && nt <= r));

            --nt;
            if (nt < 0) nt += h;
            ndp[nt] = std::max(ndp[nt], dp[pt] + (l <= nt && nt <= r));
        }

        std::swap(dp, ndp);
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}