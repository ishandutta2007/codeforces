#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

const std::string way = "SNWE";
const std::vector<int> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};

using Seg = std::pair<std::pair<int, int>, std::pair<int, int>>;

void solve() {
    std::string s;
    std::cin >> s;

    std::pair<int, int> prev(0, 0);
    std::set<Seg> segs;
    int ans = 0;

    for (char c : s) {
        auto cur = prev;

        for (int i = 0; i < 4; ++i) {
            if (c != way[i]) continue;
            cur.first += dx[i];
            cur.second += dy[i];
        }

        Seg seg(cur, prev);
        if (seg.first > seg.second) std::swap(seg.first, seg.second);
        ans += (segs.count(seg) ? 1 : 5);
        segs.insert(seg);

        prev = cur;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}