#include <iostream>
#include <vector>
#include <string>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    auto dp = vec(n + 1, vec(n + 1, 0));

    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;

            dp[l][r] = dp[l + 1][r] + 1;

            int m = l;
            while (true) {
                ++m;
                while (m < r && s[m] != s[l]) ++m;
                if (m == r) break;

                dp[l][r] = std::min(dp[l][r], dp[l + 1][m] + dp[m][r]);
            }
        }
    }

    std::cout << dp[0][n] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}