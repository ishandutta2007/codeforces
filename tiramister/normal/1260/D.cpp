#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

void solve() {
    int m, n, k, t;
    std::cin >> m >> n >> k >> t;

    std::vector<int> xs(m);
    for (auto& x : xs) std::cin >> x;
    std::sort(xs.rbegin(), xs.rend());

    std::vector<int> ls(k), rs(k), ds(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> ls[i] >> rs[i] >> ds[i];
        --ls[i];
    }

    int ok = -1, ng = m;
    // you can clear the game with level xs[ok]
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;

        std::vector<std::pair<int, int>> segs;
        for (int i = 0; i < k; ++i) {
            if (xs[mid] < ds[i]) segs.emplace_back(ls[i], rs[i]);
        }
        std::sort(segs.begin(), segs.end());

        int cost = n + 1, pr = 0;
        for (auto seg : segs) {
            if (seg.second <= pr) continue;
            seg.first = std::max(seg.first, pr);
            cost += (seg.second - seg.first) * 2;
            pr = seg.second;
        }

        (cost <= t ? ok : ng) = mid;
    }

    std::cout << ok + 1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}