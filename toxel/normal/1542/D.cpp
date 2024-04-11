#include <bits/stdc++.h>

const int N = 510;
const int moder = 998244353;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int type[N], x[N];
char input[N];
int dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", input);
        type[i] = input[0] == '+' ? 1 : 0;
        if (type[i] == 1){
            scanf("%d", &x[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (type[i] == 0){
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int j = 0; j < n; ++ j){
            if (j != i){
                memcpy(dp[j + 1], dp[j], sizeof(dp[j]));
            }
            for (int k = 0; k < N; ++ k){
                if (dp[j][k] == 0){
                    continue;
                }
                int nk;
                if (k == N - 1){
                    nk = k;
                }
                else{
                    if (type[j] == 0){
                        if (k == 1 && j > i){
                            nk = N - 1;
                        }
                        else{
                            nk = std::max(0, k - 1);
                        }
                    }
                    else{
                        bool small = x[j] < x[i] || (x[j] == x[i] && j <= i);
                        nk = k + small;
                    }
                }
                add(dp[j + 1][nk], dp[j][k]);
            }
        }
        int sum = 0;
        for (int j = 0; j < N - 1; ++ j){
            add(sum, dp[n][j]);
        }
        ans = (ans + 1ll * sum * x[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}