#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::set<std::pair<int, int>> segs;
    segs.emplace(n, 0);

    int ans = n;

    std::vector<std::pair<int, int>> wait;
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        --l;

        auto it = segs.lower_bound(std::make_pair(l, l));
        while (it != segs.end() && it->second < r) {
            auto [nr, nl] = *it;
            it = segs.erase(it);

            int len = nr - nl;
            if (nl < l) {
                wait.emplace_back(l, nl);
                len -= l - nl;
            }
            if (nr > r) {
                wait.emplace_back(nr, r);
                len -= nr - r;
            }
            ans -= len;
        }

        if (k == 2) {
            segs.emplace(r, l);
            ans += r - l;
        }

        std::cout << ans << "\n";

        while (!wait.empty()) {
            segs.insert(wait.back());
            wait.pop_back();
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}