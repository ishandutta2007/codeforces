#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
    std::function<int(int, int)> Solve = [&](int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) { dp[l][r] = a[l]; return a[l]; }
        for (int i = l; i < r; i++) {
            int L = Solve(l, i);
            int R = Solve(i + 1, r);
            if (L > 0 && R > 0 && L == R) {
                dp[l][r] = L + 1;
                return L + 1;
            }
        }
        dp[l][r] = -2;
        return dp[l][r];
    };

    std::vector<int> mn(n + 1, 1e9);
    mn[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (Solve(i, j) > 0) {
                mn[j + 1] = std::min(mn[j + 1], mn[i] + 1);
            }
        }
    }

    std::cout << mn[n] << "\n";

    return 0;
}