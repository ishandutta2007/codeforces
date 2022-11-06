#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e15;

int main() {
    int n; scanf("%d", &n);
    vector<vector<long long>> dp(5, vector<long long>(16, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        int z[4] = {x, -x, y, -y};
        vector<vector<long long>> nxt(dp.begin(), dp.end());
        for (int s = 0; s < 16; ++s) {
            for (int t = s; t < 16; ++t) {
                if ((t & s) != s) continue;
                long long k = 0;
                for (int j = 0; j < 4; ++j) {
                    if ((t >> j & 1) && !(s >> j & 1)) k += z[j];
                }
                for (int p = 0; p < 4; ++p) nxt[p + 1][t] = max(nxt[p + 1][t], dp[p][s] + k);
            }
        }
        swap(dp, nxt);
    }
    printf("%lld ", 2 * dp[3][15]);
    for (int i = 4; i <= n; ++i) printf("%lld ", 2 * dp[4][15]);
    puts("");
    return 0;
}