#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        std::vector<lint> xs(3);
        for (auto& x : xs) {
            std::cin >> x;
        }
        std::sort(xs.rbegin(), xs.rend());
        lint a = xs[0], b = xs[1] + xs[2];
        std::cout << (a <= b + 1 ? "Yes" : "No") << std::endl;
    }
    return 0;
}