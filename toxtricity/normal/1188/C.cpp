#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 1010;
const int M = 100010;

int dp[N][N], pre[N][N];
int a[M];
int comb[N][N];
int ans[M];

void add(int &a, int b){
    a += b;
    a -= a >= moder ? moder : 0;
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    ans[0] = comb[n][k];
    for (int i = 1; i * (k - 1) <= 100010; ++ i){
        for (int j = 0; j <= n; ++ j){
            for (int kk = 0; kk <= k; ++ kk){
                dp[j][kk] = 0;
                pre[j][kk] = 0;
            }
        }
        dp[0][0] = pre[0][0] = 1;
        for (int j = 1, sit = 0; j <= n; ++ j){
            while (sit <= j - 1 && a[sit] <= a[j - 1] - i){
                ++ sit;
            }
            for (int kk = 0; kk <= k; ++ kk){
                pre[j][kk] = pre[j - 1][kk];
                if (kk) {
                    dp[j][kk] = pre[sit][kk - 1];
                    add(pre[j][kk], dp[j][kk]);
                }
            }
        }
        for (int j = 0; j <= n; ++ j){
            add(ans[i], dp[j][k]);
        }
    }
    int sum = 0;
    for (int i = 0; i < M - 1; ++ i){
        sum = (sum + 1ll * i * (ans[i] - ans[i + 1])) % moder;
    }
    sum += sum < 0 ? moder : 0;
    printf("%d\n", sum);
    return 0;
}