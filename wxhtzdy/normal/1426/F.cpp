#include <bits/stdc++.h>

using i64 = long long;

const int md = 1e9 + 7;

i64 add(i64 a, i64 b) { a += b; return a >= md ? a - md : a; }
i64 mul(i64 a, i64 b) { a *= b; return a % md; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<i64> dp(4);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            for (int j = 3; j > 0; j--) dp[j] = add(mul(dp[j], 3), dp[j - 1]);
            dp[0] = mul(dp[0], 3);
        } else {
            if (s[i] == 'a') dp[1] = add(dp[1], dp[0]);
            if (s[i] == 'b') dp[2] = add(dp[2], dp[1]);
            if (s[i] == 'c') dp[3] = add(dp[3], dp[2]);
        }
    }

    std::cout << dp[3] << "\n";

    return 0;
}