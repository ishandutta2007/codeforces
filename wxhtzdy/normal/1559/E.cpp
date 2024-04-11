#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long dp[100005];
long long cur[100005];
long long pref[100005];

int main() {

    int n, m, ll[55], rr[55];
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &ll[i], &rr[i]);

    for (int d = 1; d <= m; d++) {

        int bound = m / d;
        for (int s = 0; s <= bound; s++)
            cur[s] = 0;

        cur[0] = 1;

        for (int i = 0; i < n; i++) {
            int l = (ll[i] + d - 1) / d;
            int r = rr[i] / d;

            for (int s = 0; s <= bound; s++) {
                if (s > 0) pref[s] = pref[s - 1];
                else pref[s] = 0;
                pref[s] = (pref[s] + cur[s]) % MOD;
            }

            for (int s = 0; s <= bound; s++) {
                int L = s - r, R = s - l;

                if (R < 0) { cur[s] = 0; continue; }

                cur[s] = pref[R];
                if (L > 0) cur[s] = (cur[s] - pref[L - 1] + MOD) % MOD;
            }

//            for (int s = 0; s <= bound; s++)
//                for (int j = l; j <= r; j++)
//                    if (s >= j)
//                        tmp[s] = (tmp[s] + cur[s - j]) % MOD;
        }

        for (int s = 0; s <= bound; s++)
            dp[d] = (dp[d] + cur[s]) % MOD;
    }

    for (int d = m; d > 0; d--)
        for (int i = d + d; i <= m; i += d)
            dp[d] = (dp[d] - dp[i] + MOD) % MOD;

    printf("%lld", dp[1]);
    return 0;
}