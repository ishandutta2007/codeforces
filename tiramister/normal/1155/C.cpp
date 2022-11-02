#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    lint g = 0;
    for (int i = 0; i + 1 < n; ++i) {
        g = std::gcd(g, xs[i + 1] - xs[i]);
    }

    for (int i = 1; i <= m; ++i) {
        lint p;
        std::cin >> p;
        if (g % p != 0) continue;

        std::cout << "YES\n"
                  << xs.front() << " " << i
                  << "\n";
        return;
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}