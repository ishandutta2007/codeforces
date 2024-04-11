#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <bits/stdc++.h>
using namespace std;

void upd(long long &x, long long y) {
    if (y < x) x = y;
}

int main() {
    int t, n, s, k; scanf("%d%d%d%d", &t, &n, &s, &k);
    vector<vector<int>> pos(s + 1);
    vector<vector<int>> nxt(s + 1, vector<int>(n + 1));
    vector<vector<long long>> dp(2, vector<long long>(s + 1));
    vector<int> b(n);
    const long long inf = n * 1ll * k;
    while (t--) {
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        for (int i = 0; i < 2; ++i) {
            fill(dp[i].begin(), dp[i].end(), inf);
        }
        for (int i = 0; i <= s; ++i) pos[i].clear();
        for (int i = 0; i < n; ++i) pos[b[i]].push_back(i);
        for (int i = 1; i <= s; ++i) {
            fill(nxt[i].begin(), nxt[i].end(), -1);
            for (int j = (int)pos[i].size() - 1; j >= 0; --j) {
                int p = j - 1 >= 0 ? pos[i][j - 1] : 0;
                for (int k = p; k < pos[i][j]; ++k) nxt[i][k] = pos[i][j];
            } 
        }
        dp[0][0] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            fill(dp[i & 1 ^ 1].begin(), dp[i & 1 ^ 1].end(), inf);
            for (int j = 0; j < s; ++j) {
                if (dp[i & 1][j] == inf) continue;
                ++cnt;
                upd(dp[i & 1][j + 1], dp[i & 1][j]);
                int k = dp[i & 1][j] % n;
                long long l = (dp[i & 1][j] + n - 1) / n;
                if (nxt[j + 1][k] != -1)
                    upd(dp[i & 1 ^ 1][j + 1], dp[i & 1][j] + nxt[j + 1][k] - k);
                if (pos[j + 1].size())
                    upd(dp[i & 1 ^ 1][j + 1], pos[j + 1][0] + n * l);
            }
            cnt += dp[i & 1][s] < inf;
            if (cnt) ans = i;
            else break;
        }
        for (int j = 0; j <= s; ++j) {
            if (dp[n & 1][j] < inf) ans = n;
        }
        printf("%d\n", ans);
    }
    return 0;
}