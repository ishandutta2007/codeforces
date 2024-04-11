#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(3), ys(3);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    lint min = 0;
    for (int i = 0; i < 3; ++i) {
        min += std::max(0LL, xs[i] - (ys[i] + ys[(i + 2) % 3]));
    }

    lint max = 0;
    for (int i = 0; i < 3; ++i) {
        max += std::min(xs[i], ys[(i + 1) % 3]);
    }

    std::cout << min << " " << max << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}