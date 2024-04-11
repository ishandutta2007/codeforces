#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    lint n, m, k;
    std::cin >> n >> m >> k;

    if (k < n) {
        std::cout << k + 1 << " " << 1 << std::endl;
        return;
    }
    k -= n;

    lint d = k / ((m - 1) * 2);
    k -= d * (m - 1) * 2;
    lint x = n - d * 2;

    if (k <= m - 2) {
        std::cout << x << " " << k + 2 << std::endl;
        return;
    }

    k -= m - 1;
    std::cout << x - 1 << " " << m - k << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}