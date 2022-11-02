#include <iostream>
#include <vector>

using lint = long long;

constexpr lint INF = 1LL << 60;
constexpr int N = 60;

lint prod(lint a, lint b) {
    return a >= INF / b ? INF : std::min(a * b, INF);
}

void solve() {
    lint n;
    std::cin >> n;

    std::vector<lint> cnt(N, 0);
    cnt[1] = n;

    for (int m = 2; m < N; ++m) {
        lint ok = 1, ng = cnt[m - 1] + 2;

        while (ng - ok > 1) {
            lint mid = (ok + ng) / 2;

            lint p = 1;
            for (int i = 0; i < m; ++i) p = prod(p, mid);
            if (p <= n) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        cnt[m] = ok - 1;
    }

    lint ans = n - 1;
    for (int m = N - 1; m >= 2; --m) {
        for (int x = m * 2; x < N; x += m) {
            cnt[m] -= cnt[x];
        }
        ans -= cnt[m];
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}