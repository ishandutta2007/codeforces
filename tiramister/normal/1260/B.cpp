#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);

    std::cout << ((a + b) % 3 == 0 && b <= a * 2 ? "YES" : "NO")
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