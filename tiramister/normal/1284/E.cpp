#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

using lint = long long;
using ldouble = long double;
const ldouble PI = 3.14159265358979323846338328L;

int main() {
    lint n;
    std::cin >> n;

    std::vector<ldouble> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> xs[i] >> ys[i];
    }

    lint ans = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<ldouble> args;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            ldouble dx = xs[j] - xs[i],
                    dy = ys[j] - ys[i];
            ldouble arg = std::atan2(dy, dx);
            args.push_back(arg);
            args.push_back(arg + PI * 2);
        }

        std::sort(args.begin(), args.end());
        lint pat = (n - 1) * (n - 2) / 2 * (n - 3) / 3 * (n - 4) / 4;
        for (int j = 0; j < n - 1; ++j) {
            ldouble arg = args[j];
            lint m = std::upper_bound(args.begin(), args.end(), arg + PI) -
                     std::upper_bound(args.begin(), args.end(), arg);
            pat -= m * (m - 1) * (m - 2) / 6;
        }
        assert(pat >= 0);
        ans += pat;
    }

    std::cout << ans << std::endl;
    return 0;
}