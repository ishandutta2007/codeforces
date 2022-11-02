#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, k, z;
    std::cin >> n >> k >> z;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    auto dp = vec(z + 1, vec(2, 0));
    dp[0][0] = xs[0];
    auto ndp = dp;

    for (int i = 0; i < k; ++i) {
        for (auto& v : ndp) std::fill(v.begin(), v.end(), 0);

        for (int j = 0; j <= z && i - j * 2 >= 0; ++j) {
            int idx = i - j * 2;

            // right
            for (int p = 0; p < 2; ++p) {
                ndp[j][0] = std::max(ndp[j][0], dp[j][p] + xs[idx + 1]);
            }

            // left
            if (j < z && idx > 0) {
                ndp[j + 1][1] = std::max(ndp[j + 1][1], dp[j][0] + xs[idx - 1]);
            }
        }

        dp = ndp;
    }

    int ans = 0;
    for (const auto& v : dp) {
        for (auto x : v) {
            ans = std::max(ans, x);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}