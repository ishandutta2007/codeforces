#include <iostream>
#include <iomanip>

using lint = long long;
using ldouble = long double;

void solve() {
    lint n, q;
    std::cin >> n >> q;

    lint l = n / 2 + 1,
         r = n - l + 1;

    lint sum = 0;
    while (q--) {
        lint x, d;
        std::cin >> x >> d;

        sum += x * n;
        if (d > 0) {
            sum += d * n * (n - 1) / 2;
        } else {
            sum += d * (l * (l - 1) / 2 + r * (r - 1) / 2);
        }
    }

    std::cout << std::fixed << std::setprecision(10)
              << ldouble(sum) / n << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}