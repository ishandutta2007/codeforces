#include <iostream>
#include <algorithm>

void solve() {
    int h, w, x, y;
    std::cin >> h >> w >> x >> y;
    std::cout << std::max({x * w, (h - x - 1) * w,
                           h * y, h * (w - y - 1)})
              << std::endl;
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