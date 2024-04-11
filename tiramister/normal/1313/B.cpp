#include <iostream>
#include <algorithm>

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    if (x > y) std::swap(x, y);

    std::cout << std::max(y - std::max(0, n - x - 1), 1) << " "
              << std::min(x + y - 1, n)
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