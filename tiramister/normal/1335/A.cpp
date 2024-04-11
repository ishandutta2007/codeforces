#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    std::cout << (n - 1) / 2 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}