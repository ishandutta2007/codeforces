#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    int xmax = 0, dmax = -1;
    while (n--) {
        int x, y;
        std::cin >> x >> y;
        xmax = std::max(xmax, x);
        dmax = std::max(dmax, x - y);
    }

    if (m <= xmax) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << (dmax <= 0 ? -1 : (m - xmax + dmax - 1) / dmax + 1) << std::endl;
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