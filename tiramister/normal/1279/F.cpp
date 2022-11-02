#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using ldouble = long double;
constexpr int INF = 1 << 30;

int main() {
    int n, l, k;
    std::cin >> n >> k >> l;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        char c;
        std::cin >> c;
        x = (std::islower(c) ? 1 : 0);
    }
    xs.insert(xs.begin(), 0);

    // penalty
    auto calc = [&](ldouble pena) {
        static std::vector<std::pair<ldouble, int>> dp(n + l + 1);
        dp[0] = std::make_pair(0, 0);

        for (int i = 1; i <= n + l; ++i) {
            ldouble pdist;
            int cnt;
            std::tie(pdist, cnt) = dp[i - 1];
            if (i <= n) pdist += xs[i];
            dp[i] = std::make_pair(pdist, cnt);

            if (i >= l) {
                std::tie(pdist, cnt) = dp[i - l];
                ++cnt;
                auto nxt = std::make_pair(pdist + pena, cnt);
                dp[i] = std::min(dp[i], nxt);
            }
        }
        return dp.back();
    };

    int ans = INF;
    for (int i = 0; i < 2; ++i) {
        ldouble pena = 0;

        {
            int cnt;
            std::tie(std::ignore, cnt) = calc(pena);

            // pena=0k
            if (cnt > k) {
                ldouble ok = 1e9, ng = 0;
                // pena >= ok -> used <= k

                for (int q = 0; q < 100; ++q) {
                    ldouble mid = (ok + ng) / 2;
                    int pcnt;
                    std::tie(std::ignore, pcnt) = calc(mid);
                    (pcnt <= k ? ok : ng) = mid;
                }
                pena = ok;
            }
        }

        ldouble cost;
        std::tie(cost, std::ignore) = calc(pena);
        cost -= k * pena;

        int icost = cost + 1e-10;
        ans = std::min(ans, icost);

        // 1
        for (auto& x : xs) x = 1 - x;
    }

    std::cout << ans << std::endl;
    return 0;
}