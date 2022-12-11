#include<bits/stdc++.h>

const int N = 100010;
const int M = 210;
const int moder = 998244353;

void add(int &a, int b){
    a += b;
    a -= a >= moder ? moder : 0;
}

void sub(int &a, int b){
    a -= b;
    a += a < 0 ? moder : 0;
}

int dp[N][M][2], pre[N][M][2], a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    if (a[1] == -1){
        for (int i = 1; i <= 200; ++ i){
            dp[1][i][0] = 1;
        }
    }
    else{
        dp[1][a[1]][0] = 1;
    }
    for (int i = 0; i < 2; ++ i){
        for (int j = 1; j < M; ++ j){
            pre[1][j][i] = pre[1][j - 1][i];
            add(pre[1][j][i], dp[1][j][i]);
        }
    }
    for (int i = 2; i <= n; ++ i){
        int left = a[i] == -1 ? 1 : a[i];
        int right = a[i] == -1 ? 200 : a[i];
        for (int j = left; j <= right; ++ j){
            add(dp[i][j][0], pre[i - 1][j - 1][0]);
            add(dp[i][j][0], pre[i - 1][j - 1][1]);
            add(dp[i][j][1], dp[i - 1][j][0]);
            add(dp[i][j][1], pre[i - 1][M - 1][1]);
            sub(dp[i][j][1], pre[i - 1][j - 1][1]);
        }
        for (int j = 0; j < 2; ++ j){
            for (int k = 1; k < M; ++ k){
                pre[i][k][j] = pre[i][k - 1][j];
                add(pre[i][k][j], dp[i][k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < M; ++ i){
        add(ans, dp[n][i][1]);
    }
    printf("%d\n", ans);
    return 0;
}