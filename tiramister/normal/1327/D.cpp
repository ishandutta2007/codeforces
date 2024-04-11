#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cs(n), ps(n);
    for (auto& p : ps) {
        std::cin >> p;
        --p;
    }
    for (auto& c : cs) std::cin >> c;

    std::vector<bool> visited(n, false);
    auto calc = [&](int x) {
        int i = x;
        std::vector<int> ds;

        while (ds.empty() || i != x) {
            visited[i] = true;
            ds.push_back(cs[i]);
            i = ps[i];
        }

        int m = ds.size();

        auto judge = [&](int d) {
            for (int i = 0; i < d; ++i) {
                bool ok = true;
                for (int j = i; j < m; j += d) {
                    if (ds[j] != ds[i]) ok = false;
                }
                if (ok) return true;
            }
            return false;
        };

        int ret = m;
        for (int p = 1; p * p <= m; ++p) {
            if (m % p != 0) continue;
            if (judge(p)) ret = std::min(ret, p);
            if (judge(m / p)) ret = std::min(ret, m / p);
        }
        return ret;
    };

    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) ans = std::min(ans, calc(i));
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}