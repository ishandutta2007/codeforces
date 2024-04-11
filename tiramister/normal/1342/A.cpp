#include <iostream>
#include <cmath>

using lint = long long;

void solve() {
    lint a, b, x, y;
    std::cin >> x >> y >> a >> b;

    if (x < y) std::swap(x, y);
    std::cout << std::min((x + y) * a, y * b + (x - y) * a)
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}