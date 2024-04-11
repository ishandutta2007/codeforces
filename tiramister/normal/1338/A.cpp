#include <iostream>

using lint = long long;
constexpr lint INF = 1LL << 50;

void solve() {
    int n;
    std::cin >> n;

    lint pmax = -INF, dmax = -INF;
    while (n--) {
        lint x;
        std::cin >> x;
        dmax = std::max(dmax, pmax - x);
        pmax = std::max(pmax, x);
    }

    for (int k = 0;; ++k) {
        if (dmax <= 0) {
            std::cout << k << "\n";
            break;
        }
        dmax -= (1LL << k);
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}