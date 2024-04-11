#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i] >> ys[i];
    }

    if (n % 2 != 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    for (int i = 0; i < n / 2; ++i) {
        int j = i + n / 2;
        lint dx1 = xs[i + 1] - xs[i],
             dy1 = ys[i + 1] - ys[i];
        lint dx2 = xs[(j + 1) % n] - xs[j],
             dy2 = ys[(j + 1) % n] - ys[j];

        if (dx1 * dy2 != dx2 * dy1 ||
            dx1 * dx1 + dy1 * dy1 != dx2 * dx2 + dy2 * dy2) {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    std::cout << "YES" << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}