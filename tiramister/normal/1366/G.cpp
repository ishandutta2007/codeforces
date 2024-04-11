#include <iostream>
#include <vector>
#include <string>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length();
    int m = t.length();

    std::vector<int> to(n, -1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') continue;

        int j = i + 1;
        int cnt = 1;
        while (j < n && cnt > 0) {
            if (s[j] == '.') {
                --cnt;
            } else {
                ++cnt;
            }
            ++j;
        }
        if (cnt == 0) to[i] = j;
    }

    auto dp = vec(n + 1, vec(m + 1, n + 1));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            // delete s[i]
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + 1);
        }

        if (s[i] == '.') {
            for (int j = 1; j <= m; ++j) {
                // delete the last character
                dp[i + 1][j - 1] = std::min(dp[i + 1][j - 1], dp[i][j]);
            }
        } else {
            for (int j = 0; j < m; ++j) {
                if (s[i] != t[j]) continue;
                // match
                dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
            }

            if (to[i] == -1) continue;
            for (int j = 0; j <= m; ++j) {
                // wait deleted
                dp[to[i]][j] = std::min(dp[to[i]][j], dp[i][j]);
            }
        }
    }

    std::cout << dp[n][m] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}