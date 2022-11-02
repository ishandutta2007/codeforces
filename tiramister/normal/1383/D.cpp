#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> xs(n, 0), ys(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            std::cin >> a;
            --a;

            xs[i] = std::max(xs[i], a);
            ys[j] = std::max(ys[j], a);
        }
    }

    std::sort(xs.rbegin(), xs.rend());
    std::sort(ys.rbegin(), ys.rend());
    xs.push_back(-1);
    ys.push_back(-1);

    std::vector<std::pair<int, int>> pos(n * m, std::make_pair(-1, -1));
    std::vector<std::pair<int, int>> ps;
    {
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (xs[i] == ys[j]) {
                pos[xs[i]] = std::make_pair(i, j);
                ps.emplace_back(xs[i], 0);
                ps.emplace_back(ys[j], 1);
                ++i;
                ++j;
            } else if (xs[i] > ys[j]) {
                pos[xs[i]] = std::make_pair(i, j - 1);
                ps.emplace_back(xs[i], 0);
                ++i;
            } else {
                pos[ys[j]] = std::make_pair(i - 1, j);
                ps.emplace_back(ys[j], 1);
                ++j;
            }
        }
    }

    int nxt = 0;
    while (!ps.empty()) {
        auto [a, t] = ps.back();
        ps.pop_back();

        auto [si, sj] = pos[a];

        if (t == 0) {
            for (int j = 0; j < sj; ++j) {
                while (pos[nxt].first != -1) ++nxt;
                pos[nxt] = std::make_pair(si, j);
            }
        } else {
            for (int i = 0; i < si; ++i) {
                while (pos[nxt].first != -1) ++nxt;
                pos[nxt] = std::make_pair(i, sj);
            }
        }
    }

    auto ans = vec(n, vec(m, 0));
    for (int a = 0; a < n * m; ++a) {
        auto [i, j] = pos[a];
        ans[i][j] = a;
    }

    for (const auto& v : ans) {
        for (const auto& a : v) {
            std::cout << a + 1 << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}