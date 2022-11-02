#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using lint = long long;
constexpr lint INF = 2e16;

lint dist(lint sx, lint sy, lint tx, lint ty) {
    return std::abs(sx - tx) + std::abs(sy - ty);
}

void solve() {
    std::vector<lint> xs(1), ys(1);
    lint ax, ay, bx, by;
    std::cin >> xs[0] >> ys[0] >> ax >> ay >> bx >> by;

    while (true) {
        lint x = xs.back() * ax + bx,
             y = ys.back() * ay + by;
        if (x > INF || y > INF) break;
        xs.push_back(x);
        ys.push_back(y);
    }
    int n = xs.size();

    int ans = 0;
    lint sx, sy, t;
    std::cin >> sx >> sy >> t;
    for (int i = 0; i < n; ++i) {
        lint nt = t - dist(sx, sy, xs[i], ys[i]);
        if (nt < 0) continue;

        int cnt = 1;
        ans = std::max(ans, cnt);
        for (int j = i - 1; j >= 0; --j) {
            nt -= dist(xs[j + 1], ys[j + 1], xs[j], ys[j]);
            if (nt < 0) break;
            ans = std::max(ans, ++cnt);
        }

        nt = t - dist(sx, sy, xs[i], ys[i]);
        cnt = 1;
        for (int j = i + 1; j < n; ++j) {
            nt -= dist(xs[j - 1], ys[j - 1], xs[j], ys[j]);
            if (nt < 0) break;
            ans = std::max(ans, ++cnt);
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}