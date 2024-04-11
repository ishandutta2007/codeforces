#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 30;

void solve() {
    int n, m;
    std::cin >> n >> m;

    auto cnt = vec(m, vec(m, 0));

    char p;
    std::cin >> p;
    --n;

    while (n--) {
        char c;
        std::cin >> c;
        ++cnt[p - 'a'][c - 'a'];
        p = c;
    }

    std::vector<int> dp(1 << m, INF);
    dp[0] = 0;
    for (int b = 0; b < (1 << m); ++b) {
        int pos = __builtin_popcount(b);

        for (int i = 0; i < m; ++i) {
            if ((b >> i) & 1) continue;

            int score = 0;
            for (int j = 0; j < m; ++j) {
                if (i == j) continue;
                int sign = ((b >> j) & 1) ? 1 : -1;
                score += sign * pos * (cnt[i][j] + cnt[j][i]);
            }
            dp[b | (1 << i)] = std::min(dp[b | (1 << i)], dp[b] + score);
        }
    }

    std::cout << dp.back() << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}