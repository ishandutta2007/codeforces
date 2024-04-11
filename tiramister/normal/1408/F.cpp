#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

constexpr int K = 20;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> gs(K);
    {
        int i = 1;
        for (int k = 0; k < K; ++k) {
            if ((~n >> k) & 1) continue;
            auto& g = gs[k];
            for (int j = 0; j < (1 << k); ++j) g.push_back(i++);
        }
    }

    std::vector<std::pair<int, int>> ans;
    for (const auto& g : gs) {
        int m = g.size();
        for (int s = 1; s * 2 <= m; s <<= 1) {
            for (int j = 0; j < m; j += s * 2) {
                for (int i = 0; i < s; ++i) {
                    ans.emplace_back(g[j + i], g[j + i + s]);
                }
            }
        }
    }

    int sz = __builtin_popcount(n);

    int kmax = K - 1;
    while (gs[kmax].empty()) --kmax;
    int kmin = 0;
    while (gs[kmin].empty()) ++kmin;
    auto g = std::move(gs[kmin]);
    int m = g.size();

    while (sz > 2) {
        for (int i = 0; i < m; ++i) {
            assert(!gs[kmax].empty());
            g.push_back(gs[kmax].back());
            gs[kmax].pop_back();
        }

        for (int i = 0; i < m; ++i) {
            ans.emplace_back(g[i], g[i + m]);
        }
        ++kmin;
        m = g.size();
        assert(m == (1 << kmin));

        while (sz > 2 && !gs[kmin].empty()) {
            assert(m == (1 << kmin));
            auto& f = gs[kmin];

            std::copy(f.begin(), f.end(), std::back_inserter(g));
            for (int i = 0; i < m; ++i) {
                ans.emplace_back(g[i], g[i + m]);
            }

            --sz, ++kmin;
            m = g.size();
        }
    }

    std::cout << ans.size() << "\n";
    for (auto [i, j] : ans) std::cout << i << " " << j << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}