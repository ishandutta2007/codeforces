#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using ldouble = long double;

constexpr ldouble INF = 1e10;
constexpr ldouble EPS = 1e-12;

std::pair<ldouble, ldouble> seg(int lx, int rx, int v) {
    if (v == 0) {
        if (lx < 0 && 0 < rx) {
            return {0, INF};
        } else {
            return {INF, 0};
        }
    }

    ldouble l = ldouble(lx) / v,
            r = ldouble(rx) / v;
    if (l > r) std::swap(l, r);
    return {l, r};
}

void solve() {
    int n;
    std::cin >> n;

    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;

    ldouble tl = 0, tr = INF;
    while (n--) {
        ldouble sx, sy, vx, vy;
        std::cin >> sx >> sy >> vx >> vy;

        auto [xtl, xtr] = seg(lx - sx, rx - sx, vx);
        auto [ytl, ytr] = seg(ly - sy, ry - sy, vy);

        tl = std::max({tl, xtl, ytl});
        tr = std::min({tr, xtr, ytr});
    }

    if (tl < tr - EPS) {
        std::cout << std::fixed << std::setprecision(10) << tl << '\n';
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}