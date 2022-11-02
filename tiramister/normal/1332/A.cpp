#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

void solve() {
    std::vector<lint> ps(2), ns(2);
    for (int i = 0; i < 2; ++i) std::cin >> ns[i] >> ps[i];

    std::vector<lint> xs(2), ls(2), rs(2);
    for (auto& x : xs) std::cin >> x;
    for (auto& l : ls) std::cin >> l;
    for (auto& r : rs) std::cin >> r;

    for (int i = 0; i < 2; ++i) {
        lint p = ps[i], n = ns[i],
             x = xs[i], l = ls[i], r = rs[i];

        if (l == x && x == r) {
            if (p != 0 || n != 0) {
                std::cout << "No" << std::endl;
                return;
            }
            continue;
        }

        x += p - n;

        if (x < l || r < x) {
            std::cout << "No" << std::endl;
            return;
        }
    }

    std::cout << "Yes" << std::endl;
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