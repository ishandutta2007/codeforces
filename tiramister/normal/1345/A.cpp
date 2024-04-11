#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (n > m) std::swap(n, m);
    std::cout << (n == 1 || (n == 2 && m == 2) ? "YES" : "NO")
              << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}