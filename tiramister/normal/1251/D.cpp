#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <limits>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;

    while (q--) {
        int n;
        lint s;
        std::cin >> n >> s;
        int m = (n + 1) / 2;

        std::vector<lint> ls(n), rs(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> ls[i] >> rs[i];
        }

        lint ok = 0, ng = s + 1;
        while (ng - ok > 1) {
            lint mid = (ok + ng) / 2;

            std::vector<lint> ups, lows;
            for (int i = 0; i < n; ++i) {
                (rs[i] >= mid ? ups : lows).push_back(ls[i]);
            }

            if (ups.size() < m) {
                ng = mid;
                continue;
            }

            std::sort(ups.rbegin(), ups.rend());

            lint sum = 0;
            for (int i = 0; i < ups.size(); ++i) {
                sum += (i < m ? std::max(mid, ups[i]) : ups[i]);
            }
            for (int i = 0; i < lows.size(); ++i) {
                sum += lows[i];
            }

            (sum <= s ? ok : ng) = mid;
        }
        std::cout << ok << '\n';
    }
    return 0;
}