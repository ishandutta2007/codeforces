#include <iostream>

using lint = long long;

void solve() {
    lint n, k;
    std::cin >> n >> k;

    lint d = n - k * k;
    std::cout << (d >= 0 && d % 2 == 0 ? "YES" : "NO")
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