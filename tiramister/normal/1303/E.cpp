#include <iostream>
#include <vector>
#include <string>
#include <functional>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

int dp[401][401][401];
std::string s, t;
int n, m;

int rec(int i, int j, int k) {
    auto& ret = dp[i][j][k];
    if (ret != -2) return ret;

    if (i == n) {
        return ret = (k == m ? j : -1);
    }

    ret = rec(i + 1, j, k);
    if (s[i] == t[j]) {
        ret = std::max(ret, rec(i + 1, j + 1, k));
    }
    if (s[i] == t[k]) {
        ret = std::max(ret, rec(i + 1, j, k + 1));
    }
    return ret;
}

void solve() {
    std::cin >> s >> t;
    n = s.length(), m = t.length();

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                dp[i][j][k] = -2;
            }
        }
    }

    for (int i = 0; i <= m; ++i) {
        if (rec(0, 0, i) >= i) {
            std::cout << "YES" << std::endl;
            return;
        }
    }

    std::cout << "NO" << std::endl;
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