#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = s.size();

    const int K = 20;

    std::vector<int> dp(1 << K);
    for (int i = 0; i < n; i++) {
        int msk = 0;

        for (int j = i; j < n; j++) {
            int curr = s[j] - 'a';
            if (msk & (1 << curr)) break;

            msk ^= (1 << curr);
            dp[msk] = j - i + 1;
        }
    }


    for (int msk = 0; msk < (1 << K); msk++) {
        for (int i = 0; i < K; i++) {
            if (msk & (1 << i)) {
                dp[msk] = std::max(dp[msk], dp[msk ^ (1 << i)]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << K); i++) {
        ans = std::max(ans, dp[i] + dp[((1 << K) - 1) ^ i]);
    }

    std::cout << ans << "\n";

    return 0;
}