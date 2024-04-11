#include <iostream>
#include <algorithm>

using lint = long long;

void solve() {
    lint n, m;
    std::cin >> n >> m;
    lint d = (n - m) / (m + 1),
         r = (n - m) % (m + 1);

    lint ans = d * (d + 1) / 2 * (m + 1 - r) +
               (d + 1) * (d + 2) / 2 * r;
    std::cout << n * (n + 1) / 2 - ans << std::endl;
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