#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];
ll dp[4][6];

void update(int pos, ll value){
    if (value > 0){
        if (dp[0][pos] == LLONG_MIN || dp[0][pos] < value){
            dp[0][pos] = value;
        }
        if (dp[1][pos] == LLONG_MIN || dp[1][pos] > value){
            dp[1][pos] = value;
        }
    }
    else{
        if (dp[2][pos] == LLONG_MIN || dp[2][pos] < value){
            dp[2][pos] = value;
        }
        if (dp[3][pos] == LLONG_MIN || dp[3][pos] > value){
            dp[3][pos] = value;
        }
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < 4; ++ j){
        for (int k = 0; k < 6; ++ k){
            dp[j][k] = LLONG_MIN;
        }
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 1; i <= n; ++ i){
        if (a[i - 1] == 0){
            continue;
        }
        for (int k = 4; k >= 0; -- k){
            for (int j = 0; j < 4; ++ j){
                if (dp[j][k] == LLONG_MIN){
                    continue;
                }
                update(k + 1, dp[j][k] * a[i - 1]);
            }
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 0; i < 4; ++ i){
        ans = std::max(ans, dp[i][5]);
    }
    if (ans < 0){
        for (int i = 0; i < n; ++ i){
            if (!a[i]){
                ans = 0;
                break;
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}