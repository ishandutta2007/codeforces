#include <bits/stdc++.h>

const int N = 50010;

int a[N];
int dp[N][4];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= n; ++ i){
        a[i] -= x;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 4; ++ j){
            if (dp[i - 1][j] == -1){
                continue;
            }
            for (int k = 0; k < 2; ++ k){
                int state[3] = {j & 1, j >> 1, k};
                bool flag = true;
                for (int u = -2; u <= -1; ++ u){
                    if (i + u <= 0){
                        continue;
                    }
                    bool flag1 = false;
                    for (int v = u + 2; v <= 2; ++ v){
                        if (state[v] == 0){
                            flag1 = true;
                            break;
                        }
                    }
                    if (!flag1){
                        int sum = 0;
                        for (int v = u; v <= 0; ++ v){
                            sum += a[i + v];
                        }
                        if (sum < 0){
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag){
                    int &x = dp[i][(j >> 1) | k << 1];
                    x = std::max(x, dp[i - 1][j] + k);
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 4; ++ i){
        max = std::max(max, dp[n][i]);
    }
    printf("%d\n", max);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}