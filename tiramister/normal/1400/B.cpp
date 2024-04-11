#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    std::vector<lint> xs(2), cs(2), ds(2);
    for (auto& x : xs) std::cin >> x;
    for (auto& c : cs) std::cin >> c;
    for (auto& d : ds) std::cin >> d;

    if (ds[0] > ds[1]) {
        std::swap(cs[0], cs[1]);
        std::swap(ds[0], ds[1]);
    }

    lint ans = 0;
    for (lint c00 = 0; c00 <= cs[0]; ++c00) {
        if (c00 * ds[0] > xs[0]) continue;

        lint c10 = std::min((xs[0] - c00 * ds[0]) / ds[1], cs[1]);
        lint c01 = std::min(xs[1] / ds[0], cs[0] - c00);
        lint c11 = std::min((xs[1] - c01 * ds[0]) / ds[1], cs[1] - c10);

        ans = std::max(ans, c00 + c10 + c01 + c11);
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