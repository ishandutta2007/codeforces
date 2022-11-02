#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

constexpr int INF = 1 << 30;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    std::map<int, int> ycnt;
    for (auto y : ys) ++ycnt[y];

    int ans = INF;
    for (int s = 0; s < n; ++s) {
        int d = ys[s] - xs[0];
        if (d < 0) d += m;

        auto nycnt = ycnt;
        bool judge = true;

        for (int i = 0; i < n; ++i) {
            int nx = (xs[i] + d) % m;
            if (!nycnt.count(nx) || nycnt[nx] == 0) {
                judge = false;
            } else {
                --nycnt[nx];
            }
        }

        if (judge) ans = std::min(ans, d);
    }

    assert(ans < INF);
    std::cout << ans << std::endl;
    return 0;
}