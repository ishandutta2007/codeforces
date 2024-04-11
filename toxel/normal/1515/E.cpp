#include <bits/stdc++.h>

const int N = 410;

int dp[N][N];
int fac[N], inv[N], invf[N];
int power[N];
int moder;

void addmult(int &a, int b, int c){
    a = (a + 1ll * b * c) % moder;
}

int main(){
    int n;
    scanf("%d%d", &n, &moder);
    fac[0] = invf[0] = 1;
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
        power[i] = 2ll * power[i - 1] % moder;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n - 1; ++ i){
        for (int j = 0; j < N; ++ j){
            if (dp[i][j] == 0){
                continue;
            }
            int start = i == 0 ? 1 : i + 2;
            for (int k = 1; start + k <= n + 1; ++ k){
                int coe = 1ll * power[k - 1] * invf[k] % moder;
                addmult(dp[start + k - 1][j + k], dp[i][j], coe);
            }
        }
    }
    int ans = 0;
    for (int len = 0; len < N; ++ len){
        addmult(ans, dp[n][len], fac[len]);
    }
    printf("%d\n", ans);
    return 0;
}