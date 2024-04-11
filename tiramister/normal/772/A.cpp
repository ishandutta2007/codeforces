#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using ldouble = long double;
constexpr ldouble INF = 1e15;

void solve() {
    int n;
    ldouble q;
    std::cin >> n >> q;

    std::vector<std::pair<ldouble, ldouble>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;

    ldouble ok = 0, ng = INF;
    for (int i = 0; i < 100; ++i) {
        ldouble t = (ok + ng) / 2;
        ldouble slack = q * t;

        for (auto p : ps) {
            ldouble cost = p.second - p.first * t;
            if (cost < 0) slack += cost;
        }

        if (slack >= 0) {
            ok = t;
        } else {
            ng = t;
        }
    }

    if (ok > INF / 2) {
        std::cout << -1 << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(10)
              << ok << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}