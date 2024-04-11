#include <bits/stdc++.h>

const int N = 110;
const int M = N * N;
const int K = 1000010;
const int moder = int(1e9) + 7;

int b[N];
int c[N];
int pre[N];
int dp[N][M];
int dp1[N][M];
int ans_save[K * 2];

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int solve(int n, int x){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < M; ++ i){
        dp1[0][i] = 1;
    }
    for (int i = 1; i <= n; ++ i){
        for (int k = 0; k < M; ++ k){
            add(dp[i][k], dp1[i - 1][k]);
            int pos = k - c[i] - 1;
            if (pos >= 0){
                dp[i][k] -= dp1[i - 1][pos];
                dp[i][k] += dp[i][k] < 0 ? moder : 0;
            }
        }
        for (int j = 0; j < M; ++ j){
            if (j - pre[i] < x * i){
                dp[i][j] = 0;
            }
        }
        for (int j = 0; j < M; ++ j){
            dp1[i][j] = dp[i][j];
            if (j > 0){
                add(dp1[i][j], dp1[i][j - 1]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; ++ i){
        add(ans, dp[n][i]);
    }
    return ans;
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
    int min = INT_MAX;
    for (int i = 1; i <= n; ++ i){
        min = std::min(min, -pre[i] / i - 10);
    }
    int max = min + 120;
    for (int i = min; i <= max; ++ i){
        ans_save[K + i] = solve(n, i);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int x;
        scanf("%d", &x);
        x = std::max(x, min);
        x = std::min(x, max);
        printf("%d\n", ans_save[x + K]);
    }
    return 0;
}