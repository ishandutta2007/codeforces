#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    auto xmin = *std::min_element(xs.begin(), xs.end());
    for (auto& x : xs) x -= xmin;

    auto xmax = *std::max_element(xs.begin(), xs.end());
    if (k % 2) {
        for (auto& x : xs) x = xmax - x;
    }

    for (auto x : xs) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}