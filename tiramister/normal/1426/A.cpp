#include <iostream>

void solve() {
    int n, x;
    std::cin >> n >> x;

    if (n <= 2) {
        std::cout << 1 << "\n";
    } else {
        n -= 3;
        std::cout << n / x + 2 << "\n";
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