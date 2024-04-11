#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
const std::string kind = "BRP";

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, lint>> ps(n);
    for (auto& p : ps) {
        char c;
        std::cin >> p.second >> c;

        int j = 0;
        while (c != kind[j]) ++j;
        p.first = j;
    }

    lint ans = 0;
    {
        int l = 0;
        while (l < n && ps[l].first == 0) ++l;

        while (l < n) {
            int r = l + 1;
            while (r < n && ps[r].first == 0) ++r;
            if (r == n) break;

            ans += ps[r].second - ps[l].second;
            l = r;
        }
    }

    {
        int l = 0;
        while (l < n && ps[l].first == 1) ++l;

        while (l < n) {
            int r = l + 1;
            while (r < n && ps[r].first == 1) ++r;
            if (r == n) break;

            ans += ps[r].second - ps[l].second;
            l = r;
        }
    }

    {
        int l = 0;
        while (l < n && ps[l].first != 2) ++l;

        while (l < n) {
            std::vector<std::vector<lint>> xss(2);
            for (auto& xs : xss) xs.push_back(ps[l].second);

            int r = l + 1;
            while (r < n && ps[r].first != 2) {
                xss[ps[r].first].push_back(ps[r].second);
                ++r;
            }
            if (r == n) break;

            for (auto& xs : xss) xs.push_back(ps[r].second);

            lint len = ps[r].second - ps[l].second;

            lint red = 0;
            for (auto& xs : xss) {
                lint max = 0;
                for (int i = 0; i + 1 < (int)xs.size(); ++i) {
                    max = std::max(max, xs[i + 1] - xs[i]);
                }
                red += max;
            }
            ans -= std::max(0LL, red - len);

            l = r;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}