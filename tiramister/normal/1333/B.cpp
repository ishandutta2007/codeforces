#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    bool pos = false, neg = false;
    for (int i = 0; i < n; ++i) {
        if ((ys[i] > xs[i] && !pos) ||
            (ys[i] < xs[i] && !neg)) {
            std::cout << "NO\n";
            return;
        }

        if (xs[i] > 0) pos = true;
        if (xs[i] < 0) neg = true;
    }

    std::cout << "YES\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}