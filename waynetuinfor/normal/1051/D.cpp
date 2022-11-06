#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int mod = 998244353;
int dp[maxn][maxn][4];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < 4; ++i) dp[1][0][i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int s = 0; s < 4; ++s) {
                for (int t = 0; t < 4; ++t) {
                    int s0 = (s & 1), s1 = (s >> 1 & 1);
                    int t0 = (t & 1), t1 = (t >> 1 & 1);
                    int nxt = j;
                    if (s0 == s1) {
                        if (t0 == t1 && t0 != s0) nxt++;
                    } else {
                        if (t0 != s0) nxt++;
                        if (t1 != s1) nxt++;
                    }
                    (dp[i + 1][nxt][t] += dp[i][j][s]) %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int s = 0; s < 4; ++s) {
        int s0 = (s & 1), s1 = (s >> 1 & 1);
        if (s0 == s1) {
            if (k == 0) continue;
            (ans += dp[n][k - 1][s]) %= mod;
        } else {
            if (k < 2) continue;
            (ans += dp[n][k - 2][s]) %= mod;
        }
    }
    printf("%d\n", ans);
}