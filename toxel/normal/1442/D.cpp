#include <bits/stdc++.h>

const int N = 3010;
using ll = long long;

std::vector<int> vec[N];
ll sum[N];
ll ans;

void solve(int l, int r, std::vector<ll> dp){
    int k = dp.size() - 1;
    if (l == r){
        ll tot = 0;
        for (int i = 0; i <= k; ++ i){
            if (dp[k - i] != -1){
                ans = std::max(ans, dp[k - i] + tot);
            }
            if (i < int(vec[l].size())){
                tot += vec[l][i];
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    auto update = [&](std::vector<ll> &dp, int v, ll w){
        for (int i = k; i >= 0; -- i){
            if (dp[i] == -1){
                continue;
            }
            if (i + v <= k){
                dp[i + v] = std::max(dp[i + v], dp[i] + w);
            }
        }
    };
    std::vector<ll> dp1, dp2;
    dp1 = dp2 = dp;
    for (int i = l; i <= mid; ++ i){
        update(dp2, vec[i].size(), sum[i]);
    }
    for (int i = mid + 1; i <= r; ++ i){
        update(dp1, vec[i].size(), sum[i]);
    }
    solve(l, mid, dp1);
    solve(mid + 1, r, dp2);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        int num;
        scanf("%d", &num);
        vec[i].resize(num);
        for (int j = 0; j < num; ++ j){
            scanf("%d", &vec[i][j]);
            sum[i] += vec[i][j];
        }
    }
    std::vector<ll> dp(k + 1, -1);
    dp[0] = 0;
    solve(0, n - 1, dp);
    printf("%lld\n", ans);
    return 0;
}