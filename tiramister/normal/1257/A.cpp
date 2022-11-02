#include <iostream>
#include <vector>
#include <cmath>

void solve() {
    int n, x, a, b;
    std::cin >> n >> x >> a >> b;
    std::cout << std::min(n - 1, std::abs(a - b) + x) << std::endl;
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