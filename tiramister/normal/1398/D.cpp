#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;

constexpr lint INF = 1LL << 30;

void solve() {
    std::vector<int> ns(3);
    for (auto& n : ns) std::cin >> n;

    std::vector<std::vector<lint>> xss(3);
    for (int i = 0; i < 3; ++i) {
        auto& xs = xss[i];
        xs.resize(ns[i]);

        for (auto& x : xs) std::cin >> x;
        std::sort(xs.rbegin(), xs.rend());
    }

    auto dp = vec(ns[0] + 1, vec(ns[1] + 1, vec(ns[2] + 1, -INF)));
    dp[0][0][0] = 0;
    std::vector<int> is(3);

    lint ans = 0;
    for (is[0] = 0; is[0] <= ns[0]; ++is[0]) {
        for (is[1] = 0; is[1] <= ns[1]; ++is[1]) {
            for (is[2] = 0; is[2] <= ns[2]; ++is[2]) {
                auto score = dp[is[0]][is[1]][is[2]];
                ans = std::max(ans, score);

                for (int l = 0; l < 3; ++l) {
                    int r = (l + 1) % 3;
                    if (is[l] == ns[l] || is[r] == ns[r]) continue;

                    lint area = xss[l][is[l]] * xss[r][is[r]];

                    ++is[l], ++is[r];
                    dp[is[0]][is[1]][is[2]] =
                        std::max(dp[is[0]][is[1]][is[2]], score + area);
                    --is[l], --is[r];
                }
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