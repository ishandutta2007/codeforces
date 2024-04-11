#include <bits/stdc++.h>

const int N = 110;

int p[N];
int dp[N][N][N][2];

void update(int &u, int v){
    if (v == -1){
        return;
    }
    if (u == -1 || u > v){
        u = v;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int odd = 0, even = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        if (p[i] == 0){
            continue;
        }
        ++ (p[i] % 2 == 1 ? odd : even);
    }
    odd = (n + 1) / 2 - odd;
    even = n / 2 - even;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < N; ++ j){
            for (int k = 0; k < N; ++ k){
                for (int u = 0; u < 2; ++ u){
                    if (dp[i - 1][j][k][u] == -1){
                        continue;
                    }
                    for (int v = 0; v < 2; ++ v){
                        if (p[i] != 0 && p[i] % 2 != v){
                            continue;
                        }
                        int nj = p[i] == 0 && v == 0 ? j + 1 : j;
                        int nk = p[i] == 0 && v == 1 ? k + 1 : k;
                        if (nj >= N || nk >= N){
                            continue;
                        }
                        int value = dp[i - 1][j][k][u] + (i > 1 ? int(u != v) : 0);
                        update(dp[i][nj][nk][v], value);
                    }
                }
            }
        }
    }
    int ans = dp[n][even][odd][0];
    update(ans, dp[n][even][odd][1]);
    printf("%d\n", ans);
    return 0;
}