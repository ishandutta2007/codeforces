#include <bits/stdc++.h>

const int N = 510;
const int moder = 998244353;

int a[N];
int dp[N][N];

int dfs(int l, int r){
    if (l > r){
        return 1;
    }
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    dp[l][r] = 0;
    int min = INT_MAX, sit = -1;
    for (int i = l; i <= r; ++ i){
        if (a[i] < min){
            min = a[i];
            sit = i;
        }
    }
    int prod1 = 0;
    for (int i = l; i <= sit; ++ i){
        prod1 = (prod1 + 1ll * dfs(l, i - 1) * dfs(i, sit - 1)) % moder;
    }
    int prod2 = 0;
    for (int j = sit; j <= r; ++ j){
        prod2 = (prod2 + 1ll * dfs(sit + 1, j) * dfs(j + 1, r)) % moder;
    }
    dp[l][r] = 1ll * prod1 * prod2 % moder;
    return dp[l][r];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        -- a[i];
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(0, n - 1));
}