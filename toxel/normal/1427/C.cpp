#include <bits/stdc++.h>

const int N = 200010;

int dp[N];
int x[N], y[N], t[N];
int pre_max[N];

int main(){
    int r, n;
    scanf("%d%d", &r, &n);
    memset(dp, -1, sizeof(dp));
    x[0] = y[0] = 1;
    t[0] = 0;
    dp[0] = pre_max[0] = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++ i){
        int tt = -1;
        for (int j = i - 1; j >= 0; -- j){
            if (t[i] - t[j] >= 2 * r){
                tt = j;
                break;
            }
            if (dp[j] == -1){
                continue;
            }
            if (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) <= t[i] - t[j]){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        if (tt != -1){
            dp[i] = std::max(dp[i], pre_max[tt] + 1);
        }
        pre_max[i] = std::max(pre_max[i - 1], dp[i]);
    }
    printf("%d\n", pre_max[n]);
    return 0;
}