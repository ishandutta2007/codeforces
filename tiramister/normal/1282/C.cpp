#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        lint t, a, b;
        std::cin >> n >> t >> a >> b;

        std::vector<std::pair<lint, lint>> ps(n);
        std::vector<lint> cnt(2, 0);
        for (auto& p : ps) {
            std::cin >> p.second;
            ++cnt[p.second];
        }
        for (auto& p : ps) std::cin >> p.first;

        ps.emplace_back(t + 1, 0);
        std::sort(ps.begin(), ps.end());

        int ans = 0;
        lint s = 0;
        for (int i = -1; i < n; ++i) {
            if (i >= 0) {
                s += (ps[i].second ? b : a);
                --cnt[ps[i].second];
            }

            lint rem = ps[i + 1].first - s - 1;
            if (rem >= 0) {
                int solved = i + 1;
                int easy = std::min(cnt[0], rem / a);
                rem -= easy * a;
                int hard = std::min(cnt[1], rem / b);
                rem -= hard * b;
                ans = std::max(ans, solved + easy + hard);
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}