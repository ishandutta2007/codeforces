#include <iostream>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    n /= 2;
    if (n % 2 == 1) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;

    lint d = 0;
    for (int i = 1; i <= n; ++i) {
        std::cout << i * 2 << " ";
        d += i * 2;
    }
    for (int i = 1; i < n; ++i) {
        std::cout << i * 2 - 1 << " ";
        d -= i * 2 - 1;
    }
    std::cout << d << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}