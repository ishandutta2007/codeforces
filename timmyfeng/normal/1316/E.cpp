#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<vector<int>> s(n , vector<int>(p));
    for (auto& i : s) {
        for (auto& j : i) {
            cin >> j;
        }
    }

    vector<int> ndx(n + 1);
    iota(ndx.begin() + 1, ndx.end(), 0);
    sort(ndx.begin() + 1, ndx.end(), [&](int i, int j){ return a[i] > a[j]; });

    vector<vector<long long>> dp(n + 1, vector<long long>(1 << p, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) {
            if (dp[i - 1][mask] != -1) {
                dp[i][mask] = dp[i - 1][mask];
                int free = i - 1 - __builtin_popcount(mask);
                if (free < k) {
                    dp[i][mask] += a[ndx[i]];
                }
            }
            for (int k = 0; k < p; ++k) {
                int newMask = mask & ~(1 << k);
                if (mask != newMask && dp[i - 1][newMask] != -1) {
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][newMask] + s[ndx[i]][k]);
                }
            }
        }
    }
    cout << dp[n].back() << '\n';
}