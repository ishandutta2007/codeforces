#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n, p, k;
        std::cin >> n >> p >> k;

        std::vector<int> xs(n);
        for (auto& x : xs) std::cin >> x;
        xs.push_back(0);
        std::sort(xs.begin(), xs.end());

        for (int i = 1; i <= n; ++i) {
            xs[i] += (i < k ? xs[i - 1] : xs[i - k]);
        }

        for (int i = n; i >= 0; --i) {
            if (xs[i] <= p) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}