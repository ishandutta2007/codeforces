#include <iostream>
#include <vector>

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, r;
    lint k;
    std::cin >> n >> r >> k;

    std::vector<lint> init(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        lint a;
        std::cin >> a;
        init[std::max(i - r, 0)] += a;
        init[std::min(i + r + 1, n)] -= a;
    }

    for (int i = 0; i < n; ++i) {
        init[i + 1] += init[i];
    }

    lint ok = 0, ng = INF;
    while (ng - ok > 1) {
        lint mid = (ok + ng) / 2;

        std::vector<lint> needs(n, 0);
        for (int i = 0; i < n; ++i) {
            needs[i] = mid - init[i];
        }

        std::vector<lint> eff(n + 1, 0);
        lint cnt = 0, cur = 0;

        for (int i = 0; i < n; ++i) {
            cur += eff[i];
            needs[i] -= cur;

            lint need = std::max(needs[i], 0LL);
            eff[std::min(i + r * 2 + 1, n)] -= need;
            cnt += need;
            cur += need;

            if (cnt > k) break;
        }

        if (cnt <= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ok << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}