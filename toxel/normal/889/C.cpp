#include<bits/stdc++.h>

const int moder = (int) 1e9 + 7;
const int N = 1000010;

int fac[N], inv[N], dp[N], pre[N];

void init(){
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
}

int main(){
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0] = pre[0] = 1;
    for (int i = 1; i <= n; ++ i){
        dp[i] = pre[i - 1] - (i - k - 1 < 0 ? 0 : pre[i - k - 1]);
        dp[i] += dp[i] < 0 ? moder : 0;
        dp[i] = 1ll * dp[i] * inv[i] % moder;
        pre[i] = pre[i - 1] + dp[i];
        pre[i] -= pre[i] >= moder ? moder : 0;
    }
    int ans = fac[n];
    for (int i = 1; i <= n; ++ i){
        ans = (ans - 1ll * fac[n] * inv[n] % moder * dp[n - i]) % moder;
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}