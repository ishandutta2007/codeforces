#include <iostream>
#include <iomanip>
#include <vector>

using lint = long long;
using ldouble = long double;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<ldouble> xs(n);
    for (auto& x : xs) std::cin >> x;
    xs.insert(xs.begin(), 0);
    xs.push_back(m);

    ldouble ok = 0, ng = 1e10;
    for (int q = 0; q < 100; ++q) {
        ldouble t = (ok + ng) / 2;

        ldouble f = 0, ft = t;
        for (int i = 1; i <= n + 1; ++i) {
            ldouble d = std::min(xs[i] - xs[i - 1], ft * i);
            f += d;
            ft -= d / i;
        }

        ldouble b = 0, bt = t;
        for (int i = n; i >= 0; --i) {
            ldouble d = std::min(xs[i + 1] - xs[i], bt * (n + 1 - i));
            b += d;
            bt -= d / (n + 1 - i);
        }

        if (f + b <= m) {
            ok = t;
        } else {
            ng = t;
        }
    }

    std::cout << std::fixed << std::setprecision(10) << ok << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}