#include <bits/stdc++.h>

const int N = 4010;
const int BIT = 12;
const int INF = int(0xc0c0'c0c0);

int dp[N][1 << BIT], dp1[N];
int l[N], s[N], c[N];
int lb[N];
int pre[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, 0xc0, sizeof(dp));
    memset(dp1, 0xc0, sizeof(dp1));
    for (int i = 0; i < n; ++ i){
        scanf("%d", &l[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n + m; ++ i){
        scanf("%d", &c[i]);
        pre[i] = pre[i - 1] + c[i];
    }
    for (int i = 1; i < N; ++ i){
        lb[i] = i & 1 ? 0 : lb[i >> 1] + 1;
    }
    dp[0][0] = dp1[0] = 0;
    for (int i = n - 1; i >= 0; -- i){
        for (int j = l[i]; j >= l[i] - BIT && j >= 0; -- j){
            for (int bit = (1 << BIT) - 1; bit >= 0; -- bit){
                if (dp[j][bit] == INF){
                    continue;
                }
                int bbit = bit >> (l[i] - j);
                ++ bbit;
                int nvalue = dp[j][bit] - s[i] + pre[l[i] + lb[bbit]] - pre[l[i] - 1];
                dp[l[i]][bbit] = std::max(dp[l[i]][bbit], nvalue);
                dp1[l[i]] = std::max(dp1[l[i]], nvalue);
            }
        }
        for (int j = 0; j < l[i] - BIT; ++ j){
            if (dp1[j] == INF){
                continue;
            }
            int nvalue = dp1[j] + c[l[i]] - s[i];
            dp1[l[i]] = std::max(dp1[l[i]], nvalue);
            dp[l[i]][1] = std::max(dp[l[i]][1], nvalue);
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < N; ++ i){
        ans = std::max(ans, dp1[i]);
    }
    printf("%d\n", ans);
    return 0;
}