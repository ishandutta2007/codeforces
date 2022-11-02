#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 30;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> ps(n);
    for (auto& p : ps) std::cin >> p.second >> p.first;

    std::vector<int> idxs(n, 0);
    std::iota(idxs.begin(), idxs.end(), 0);
    std::sort(idxs.begin(), idxs.end(),
              [&](int i, int j) { return ps[i] < ps[j]; });

    std::sort(ps.begin(), ps.end());
    ps.emplace(ps.begin(), 0, 0);
    ps.emplace_back(0, 0);

    auto dp = vec(n + 2, vec(m + 2, -INF));
    auto rev = vec(n + 2, vec(m + 2, -1));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k <= m; ++k) {
            int sum = dp[i][k];
            for (int j = i + 1; j <= n + 1; ++j) {
                int score = sum + ps[j].first * k + ps[j].second;
                sum += ps[j].first * (m - 1);

                if (k == m && j <= n) continue;
                if (score < dp[j][k + 1]) continue;
                dp[j][k + 1] = score;
                rev[j][k + 1] = i;
            }
        }
    }

    std::vector<int> used(n + 2, 1);
    {
        int i = n + 1;
        for (int k = m + 1; k > 0; --k) {
            used[i] = (k == m ? 2 : 0);
            i = rev[i][k];
        }
    }

    std::cout << n * 2 - m << "\n";
    for (int t = 0; t <= 2; ++t) {
        for (int i = 1; i <= n; ++i) {
            if (used[i] != t) continue;

            int idx = idxs[i - 1] + 1;
            std::cout << idx << " ";
            if (t == 1) std::cout << -idx << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}