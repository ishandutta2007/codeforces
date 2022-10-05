#include<bits/stdc++.h>

const int N = 1010;
const int moder = 998244353;

int pre[N], dp[N], a[N];
int comb[N][N];

int com(int n, int m){
    if (m < 0 || n < m) return 0;
    return comb[n][m];
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] -= comb[i][j] >= moder ? moder : 0;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        if (a[i] > 0){
            for (int j = i + 1; j < n; ++ j){
                dp[j] = (dp[j] + 1ll * (i ? pre[i - 1] + 1 : 1) * com(j - i - 1, a[i] - 1)) % moder;
            }
        }
        pre[i] = i ? pre[i - 1] + dp[i] : dp[i];
        pre[i] -= pre[i] >= moder ? moder : 0;
    }
    printf("%d\n", pre[n - 1]);
    return 0;
}