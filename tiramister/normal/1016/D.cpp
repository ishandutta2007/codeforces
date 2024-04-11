#include <iostream>
#include <numeric>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ys(m);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    auto xsum = std::accumulate(xs.begin(), xs.end(), 0,
                                [](auto acc, auto x) { return acc ^ x; });
    auto ysum = std::accumulate(ys.begin(), ys.end(), 0,
                                [](auto acc, auto y) { return acc ^ y; });

    if (xsum != ysum) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            std::cout << "0 ";
        }
        std::cout << xs[i] << "\n";
    }

    for (int j = 0; j < m - 1; ++j) {
        std::cout << ys[j] << " ";
    }

    std::cout << (xsum ^ xs.back() ^ ys.back()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}