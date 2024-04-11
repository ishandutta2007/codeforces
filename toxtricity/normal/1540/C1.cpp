#include <bits/stdc++.h>

const int N = 110;
const int M = N * N;
const int moder = int(1e9) + 7;

int b[N];
int c[N];
int pre[N];
int dp[N][M];

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void solve(int n){
    memset(dp, 0, sizeof(dp));
    int x;
    scanf("%d", &x);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++ i){
        for (int k = 0; k < M; ++ k){
            if (dp[i - 1][k]){
                for (int j = 0; j <= c[i]; ++ j){
                    add(dp[i][k + j], dp[i - 1][k]);
                }
            }
        }
        for (int j = 0; j < M; ++ j){
            if (j - pre[i] < x * i){
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; ++ i){
        add(ans, dp[n][i]);
    }
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    for (int i = 1; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 2; i <= n; ++ i){
        pre[i] = pre[i - 1] + b[i - 1];
    }
    for (int i = 2; i <= n; ++ i){
        pre[i] += pre[i - 1];
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve(n);
    }
    return 0;
}