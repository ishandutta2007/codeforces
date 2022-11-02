#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ps(m);
    for (auto& x : xs) std::cin >> x;
    for (auto& p : ps) {
        std::cin >> p;
        --p;
    }

    bool update = true;
    while (update) {
        update = false;
        for (int p : ps) {
            if (xs[p] > xs[p + 1]) {
                std::swap(xs[p], xs[p + 1]);
                update = true;
            }
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (xs[i] > xs[i + 1]) {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    std::cout << "YES" << std::endl;
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