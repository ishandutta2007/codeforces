#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<bool> blocked(n, false);
    while (m--) {
        int x;
        std::cin >> x;
        blocked[x] = true;
    }

    std::vector<int> xs;
    for (int x = 0; x < n; ++x) {
        if (!blocked[x]) xs.push_back(x);
    }
    xs.push_back(n);

    std::vector<lint> costs(k);
    for (auto& c : costs) std::cin >> c;

    lint ans = INF;
    for (int d = 1; d <= k; ++d) {
        int x = n;
        lint cnt = 0;
        while (x > 0) {
            int nxt = *std::lower_bound(xs.begin(), xs.end(), x - d);
            if (nxt == x) break;
            x = nxt;
            ++cnt;
        }
        if (x == 0) ans = std::min(ans, costs[d - 1] * cnt);
    }

    std::cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}