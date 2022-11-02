#include <iostream>
#include <iomanip>
#include <vector>

using lint = long long;
using ldouble = long double;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<lint, lint>> segs;
    while (n--) {
        lint x;
        std::cin >> x;
        std::pair<lint, lint> p(x, 1);

        while (!segs.empty()) {
            auto a = segs.back();
            if (a.first * p.second < a.second * p.first) {
                segs.push_back(p);
                break;
            } else {
                p.first += a.first;
                p.second += a.second;
                segs.pop_back();
            }
        }
        if (segs.empty()) segs.push_back(p);
    }

    std::cout << std::fixed << std::setprecision(10);
    for (auto p : segs) {
        ldouble ave = ldouble(p.first) / p.second;
        for (int i = 0; i < p.second; ++i) {
            std::cout << ave << "\n";
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}