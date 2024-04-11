#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << (n % m == 0 ? "YES" : "NO") << std::endl;
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