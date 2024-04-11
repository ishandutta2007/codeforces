#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    auto dp = vec(n + 1, vec(n + 1, -1));
    for (int i = 0; i < n; ++i) {
        std::cin >> dp[i][i + 1];
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            for (int i = l + 1; i <= r - 1; ++i) {
                int vl = dp[l][i], vr = dp[i][r];
                if (vl == -1 || vl != vr) continue;
                dp[l][r] = vl + 1;
            }
        }
    }

    auto ans = vec(n + 1, n + 1);
    ans[0] = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r <= n; ++r) {
            if (dp[l][r] == -1) continue;
            ans[r] = std::min(ans[r], ans[l] + 1);
        }
    }

    std::cout << ans.back() << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}