#include <bits/stdc++.h>

const int N = 100010;

char s[2][N];
int dp[N], left[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2; ++ i){
        scanf("%s", s[i] + 1);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++ i){
        if (s[0][i] != s[1][i]){
            left[i] = -1;
        }
        else{
            if (i >= 1 && s[0][i] == s[0][i - 1] && s[1][i] == s[1][i - 1]){
                left[i] = left[i - 1];
            }
            else{
                left[i] = i;
            }
        }
        if (left[i] == -1){
            dp[i] = dp[i - 1] + 2;
        }
        else{
            dp[i] = dp[i - 1] + (s[0][i] == '0' ? 1 : 0);
            if (left[i] > 1){
                dp[i] = std::max(dp[i], dp[left[i] - 2] + 2);
            }
        }
    }
    printf("%d\n", dp[n]);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}