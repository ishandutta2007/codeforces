#include <iostream>

using lint = long long;

void solve() {
    lint h, c, t;
    std::cin >> h >> c >> t;

    if (t >= h) {
        std::cout << "1\n";
        return;
    }

    if (t * 2 <= h + c) {
        std::cout << "2\n";
        return;
    }

    lint k = (h - t) / (t * 2 - h - c);

    lint ans = k * 2 + 1;
    if ((k * 2 + 3) * (((k + 1) * h + (k + 0) * c) - t * (k * 2 + 1)) >
        (k * 2 + 1) * (t * (k * 2 + 3) - ((k + 2) * h + (k + 1) * c))) {
        ans = k * 2 + 3;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}