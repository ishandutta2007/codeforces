#include <iostream>
#include <algorithm>
#include <vector>

constexpr int INF = 1000000000;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }

    int w = 1;
    for (int i = 0; i + 1 < n; ++i) {
        w = std::max(w, std::abs(xs[i + 1] - xs[i]));
    }

    auto dec = [&](int p) {
        return std::make_pair(p / w, p % w);
    };

    for (int i = 0; i + 1 < n; ++i) {
        auto [x1, y1] = dec(xs[i]);
        auto [x2, y2] = dec(xs[i + 1]);

        if (std::abs(x1 - x2) + std::abs(y1 - y2) != 1) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n"
              << INF << " " << w << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}