#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    std::sort(xs.begin(), xs.end());
    std::sort(ys.rbegin(), ys.rend());

    for (int i = 0; i < n; ++i) {
        if (xs[i] + ys[i] > m) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}