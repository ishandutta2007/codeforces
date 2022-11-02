#include <iostream>

using lint = long long;

void solve() {
    lint n;
    std::cin >> n;

    lint ans = 0;
    for (int k = 0; k < 60; ++k) {
        ans += (n >> k);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}