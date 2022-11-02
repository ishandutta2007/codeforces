#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto xss = vec(n, vec(m, 0));
    for (auto& xs : xss) {
        for (auto& x : xs) {
            std::cin >> x;
        }
    }

    int ok = -1, ng = 1 << 30;
    int ai, aj;
    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        auto dp = vec(1 << m, -1);

        for (int i = 0; i < n; ++i) {
            int b = 0;
            for (int j = 0; j < m; ++j) {
                if (xss[i][j] >= mid) b |= (1 << j);
            }
            dp[b] = i;
        }

        bool judge = false;
        for (int lb = 0; lb < (1 << m); ++lb) {
            if (dp[lb] < 0) continue;
            for (int rb = 0; rb < (1 << m); ++rb) {
                if (dp[rb] < 0) continue;

                if ((lb | rb) == ((1 << m) - 1)) {
                    ai = dp[lb];
                    aj = dp[rb];
                    judge = true;
                }
            }
        }

        (judge ? ok : ng) = mid;
    }

    std::cout << ai + 1 << " " << aj + 1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}