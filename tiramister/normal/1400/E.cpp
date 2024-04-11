#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    auto ys = xs;
    ys.push_back(0);
    auto yrev = compress(ys);
    int m = ys.size();

    std::vector<lint> dp(m, INF);
    dp[0] = 0;
    auto ndp = dp;

    for (auto x : xs) {
        int xi = yrev[x];

        std::fill(ndp.begin(), ndp.end(), INF);
        for (int yi = 0; yi < m; ++yi) {
            if (yi >= xi) {
                ndp[xi] = std::min(ndp[xi], dp[yi]);
            } else {
                // use
                ndp[xi] = std::min(ndp[xi], dp[yi] + (ys[xi] - ys[yi]));
                // pass
                ndp[yi] = std::min(ndp[yi], dp[yi] + 1);
            }
        }
        std::swap(dp, ndp);
    }

    std::cout << *std::min_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}