#include<bits/stdc++.h>

const int N = 100010;

int p[N], inv[N], dp[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
        inv[p[i]] = i;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; ++ i){
        if (inv[i - 1] < inv[i]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans = std::max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
    return 0;
}