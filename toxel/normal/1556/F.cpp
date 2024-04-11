#include <bits/stdc++.h>

const int N = 15;
const int moder = int(1e9) + 7;

int a[N];
int prob[N][N];
int dp[1 << N], bitcnt[1 << N];
int pre[N][1 << N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    for (int i = 1; i < 1 << N; ++ i){
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i == j){
                continue;
            }
            prob[i][j] = 1ll * powermod(a[i] + a[j], moder - 2) * a[i] % moder;
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 1 << n; ++ j){
            pre[i][j] = 1;
            for (int k = 0; k < n; ++ k){
                if (j >> k & 1){
                    pre[i][j] = 1ll * pre[i][j] * prob[i][k + 1] % moder;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 1 << n; ++ i){
        if (bitcnt[i] == 1){
            dp[i] = 1;
        }
        else{
            dp[i] = 1;
            for (int j = (i - 1) & i; j > 0; j = (j - 1) & i){
                int prod = 1;
                for (int k = 0; k < n; ++ k){
                    if (j >> k & 1){
                        prod = 1ll * prod * pre[k + 1][i ^ j] % moder;
                    }
                }
                dp[i] = (dp[i] - 1ll * dp[j] * prod) % moder;
            }
            dp[i] += dp[i] < 0 ? moder : 0;
        }
        int prod = 1;
        for (int j = 0; j < n; ++ j){
            if (i >> j & 1){
                prod = 1ll * prod * pre[j + 1][((1 << n) - 1) ^ i] % moder;
            }
        }
        ans = (ans + 1ll * dp[i] * prod % moder * bitcnt[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}