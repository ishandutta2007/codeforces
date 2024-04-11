#include <iostream>

void solve() {
    int k;
    std::cin >> k;

    std::cout << 2 << " " << 3 << std::endl
              << (1 << 18) - 1 << " " << (1 << 17) << " " << 0 << std::endl
              << k << " " << (1 << 18) - 1 << " " << (1 << 17) - 1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}