#include<bits/stdc++.h>

const int N = 410;

int dp[N][N], ans[N], dp1[N];
int moder;
int fac[N], inv[N], invf[N];

void init(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    for (int i = 1; i < N; ++ i){
        dp1[i] = fac[i];
        for (int j = 1; j < i; ++ j){
            dp1[i] = (dp1[i] - 1ll * dp1[j] * fac[i - j]) % moder;
        }
        dp1[i] += dp1[i] < 0 ? moder : 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            for (int k = 1; k < N; ++ k){
                if (i + k >= N){
                    break;
                }
                int &u = dp[i + k][j + 1];
                u = (u + 1ll * dp[i][j] * fac[k]) % moder;
            }
        }
    }
    for (int i = 1; i < N; ++ i){
        ans[i] = fac[i];
        for (int j = 1; j < i; ++ j){
            ans[i] = (ans[i] - 2ll * dp1[j] * fac[i - j]) % moder;
        }
        for (int j = 4; j < i; ++ j){
            ans[i] = (ans[i] - 1ll * ans[j] * dp[i][j]) % moder;
        }
        ans[i] += ans[i] < 0 ? moder : 0;
    }
}

int main(){
    int test;
    scanf("%d%d", &test, &moder);
    init();
    ans[2] = 2;
    while (test --){
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}