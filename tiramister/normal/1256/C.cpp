#include <iostream>
#include <numeric>
#include <vector>

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> xs(m);
    for (auto& x : xs) std::cin >> x;

    int r = n - std::accumulate(xs.begin(), xs.end(), 0);

    if ((m + 1) * (d - 1) < r) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;

    for (int i = 0; i < m; ++i) {
        int sp = r / (m + 1 - i);

        while (sp--) {
            std::cout << 0 << " ";
            --r;
        }

        while (xs[i]--) {
            std::cout << i + 1 << " ";
        }
    }

    while (r--) std::cout << 0 << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}