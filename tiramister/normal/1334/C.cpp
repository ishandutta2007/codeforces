#include <iostream>
#include <vector>

using lint = long long;

constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n), ys(n);
    for (int i = 0; i < n; ++i) std::cin >> xs[i] >> ys[i];

    lint ans = 0, dmin = INF;
    for (int i = 0; i < n; ++i) {
        int j = (i == 0 ? n - 1 : i - 1);
        auto d = std::min(xs[i], ys[j]);

        ans += xs[i] - d;
        dmin = std::min(dmin, d);
    }

    std::cout << ans + dmin << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}