#include<bits/stdc++.h>

const int N = 110;
const int moder = (int) 1e9 + 9;

int dp[N][N * N];
int comb[N][N];
int a[N], cnt[N];

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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ cnt[a[i]];
    }
    int ccnt = 0;
    for (int i = 0; i < N; ++ i){
        if (cnt[i]){
            ++ ccnt;
        }
    }
    if (ccnt <= 2){
        printf("%d\n", n);
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++ i){
        for (int j = i - 1; j >= 0; -- j){
            for (int k = 0; k < N * N; ++ k){
                if (k + a[i - 1] >= N * N){
                    break;
                }
                add(dp[j + 1][k + a[i - 1]], dp[j][k]);
            }
        }
    }
    int max = 0;
    for (int i = 1; i < N; ++ i){
        for (int j = 1; j <= cnt[i]; ++ j){
            if (dp[j][j * i] == comb[cnt[i]][j]){
                max = std::max(max, j);
            }
        }
    }
    printf("%d\n", max);
    return 0;
}