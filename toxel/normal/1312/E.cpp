#include <bits/stdc++.h>

const int N = 510;

int merge[N][N];
int a[N];
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    memset(merge, -1, sizeof(merge));
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        merge[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++ len){
        for (int i = 0; i < n; ++ i){
            int j = i + len - 1;
            if (j >= n){
                break;
            }
            for (int k = i; k < j; ++ k){
                if (merge[i][k] != -1 && merge[i][k] == merge[k + 1][j]){
                    merge[i][j] = merge[i][k] + 1;
                    break;
                }
            }
        }
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (merge[j][i] != -1){
                dp[i + 1] = std::min(dp[i + 1], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}