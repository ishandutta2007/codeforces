#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<int> ys;
    for (int i = 0; i + 1 < n; ++i) {
        if (xs[i] == -1 && xs[i + 1] == -1) continue;
        if (xs[i] == -1) ys.push_back(xs[i + 1]);
        if (xs[i + 1] == -1) ys.push_back(xs[i]);
    }

    if (ys.empty()) {
        std::cout << 0 << " " << 0 << std::endl;
        return;
    }

    std::sort(ys.begin(), ys.end());
    int k = (ys.front() + ys.back()) / 2;

    for (auto& x : xs) {
        if (x == -1) x = k;
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ans = std::max(ans, std::abs(xs[i + 1] - xs[i]));
    }
    std::cout << ans << " " << k << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}