#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;

        std::vector<int> xs(n);
        for (auto& x : xs) std::cin >> x;

        bool judge = false;
        for (int i = 0; i + 1 < n; ++i) {
            if (std::abs(xs[i] - xs[i + 1]) > 1) {
                std::cout << "YES\n"
                          << i + 1 << " " << i + 2 << "\n";
                judge = true;
                break;
            }
        }
        if (!judge) {
            std::cout << "NO\n";
        }
    }
    return 0;
}