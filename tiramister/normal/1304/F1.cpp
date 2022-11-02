#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1 << 30;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> xs(m), dp(m + 1, -INF), ndp(m + 1);
    dp[m] = 0;
    while (n--) {
        for (auto& x : xs) std::cin >> x;

        std::vector<int> psum(m + 1, 0);  // [0, i)
        for (int l = 0; l < m; ++l) {
            psum[l + 1] = psum[l] + xs[l];
        }

        // [l, r)
        auto score = [&](int l, int r) {
            return psum[std::min(r, m)] - psum[std::max(0, l)];
        };

        // [0, i)
        std::vector<int> fmax(m + 2, -INF);
        for (int l = 0; l <= m; ++l) {
            fmax[l + 1] = std::max(fmax[l], dp[l] + score(l, l + k));
        }

        // [i, m)
        std::vector<int> bmax(m + 2, -INF);
        for (int l = m; l >= 0; --l) {
            bmax[l] = std::max(bmax[l + 1], dp[l] + score(l, l + k));
        }

        for (int l = 0; l <= m; ++l) {
            ndp[l] = std::max(fmax[std::max(0, l - k + 1)],
                              bmax[std::min(l + k, m)]) +
                     score(l, l + k);

            for (int pl = l - k + 1; pl < l + k; ++pl) {
                if (pl < 0 || m <= pl) continue;
                int ml = std::min(l, pl),
                    mr = std::max(l, pl) + k;
                ndp[l] = std::max(ndp[l], dp[pl] + score(ml, mr));
            }
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