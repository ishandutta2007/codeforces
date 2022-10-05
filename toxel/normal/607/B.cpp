#include<bits/stdc++.h>

const int N = 510;

int dp[N][N];
int s[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; ++ i){
        dp[i][i] = 1;
    }
    for (int len = 1; len < n; ++ len){
        for (int i = 0; i + len < n; ++ i){
            if (s[i] == s[i + len]){
                dp[i][i + len] = len == 1 ? 1 : dp[i + 1][i + len - 1];
            }
            else{
                dp[i][i + len] = INT_MAX;
            }
            for (int j = i; j < i + len; ++ j){
                dp[i][i + len] = std::min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len]);
            }
        }
    }
    printf("%d\n", dp[0][n - 1]);
    return 0;
}