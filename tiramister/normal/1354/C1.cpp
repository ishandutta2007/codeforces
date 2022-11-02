#include <iostream>
#include <iomanip>
#include <cmath>

using ldouble = long double;
const ldouble PI = std::acos(-1L);

void solve() {
    int n;
    std::cin >> n;

    auto calc = [&](ldouble theta) {
        ldouble xmax = 0, xmin = 0,
                ymax = 0, ymin = 0;

        for (int i = 0; i < n * 2; ++i) {
            ldouble phi = theta + PI * i / n;
            ldouble x = std::cos(phi);
            ldouble y = std::sin(phi);

            xmax = std::max(xmax, x);
            xmin = std::min(xmin, x);
            ymax = std::max(ymax, y);
            ymin = std::min(ymin, y);
        }

        return std::max(xmax - xmin, ymax - ymin);
    };

    ldouble l = 0,
            r = PI / (n * 2);

    for (int i = 0; i < 100; ++i) {
        ldouble ll = (l * 2 + r) / 3,
                rr = (l + r * 2) / 3;

        if (calc(ll) > calc(rr)) {
            l = ll;
        } else {
            r = rr;
        }
    }

    std::cout << calc(l) / (std::sin(PI / (n * 2)) * 2) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cout << std::fixed << std::setprecision(10);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}