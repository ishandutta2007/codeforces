#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

void solve() {
    int n, w, h;
    std::cin >> n >> w >> h;

    std::map<int, std::vector<std::tuple<int, int, int>>> tss;
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        std::cin >> g >> p >> t;
        if (g == 1) {
            tss[p - t].emplace_back(0, p, i);
        } else {
            tss[p - t].emplace_back(-p, 0, i);
        }
    }

    std::vector<std::pair<int, int>> ans(n);
    for (auto& [d, ts] : tss) {
        std::sort(ts.begin(), ts.end());
        int m = ts.size();

        int j = 0;
        while (j < m && std::get<0>(ts[j]) != 0) ++j;
        j %= m;

        for (int i = 0; i < m; ++i, (++j) %= m) {
            auto [iy, ix, iid] = ts[i];
            auto [jy, jx, jid] = ts[j];
            ans[iid] = std::make_pair(jx == 0 ? w : jx,
                                      jy == 0 ? h : -jy);
        }
    }

    for (auto [x, y] : ans) std::cout << x << " " << y << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}