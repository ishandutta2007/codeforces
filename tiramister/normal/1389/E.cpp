#include <iostream>
#include <numeric>

using lint = long long;

void solve() {
    lint m, d, w;
    std::cin >> m >> d >> w;
    m = std::min(m, d);

    w /= std::gcd(w, d - 1);
    lint n = (m - 1) / w;

    std::cout << n * m - w * n * (n + 1) / 2 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}