#include <bits/stdc++.h>

const int N = 100010;
const int moder = (int) 1e9 + 7;

int dp[N];
char s[N];

int main(){
    dp[0] = dp[1] = 1;
    for (int i = 2; i < N; ++ i){
        dp[i] = 2 * (i >= 2 ? dp[i - 2] : 0) % moder;
        if (i >= 3){
            dp[i] += dp[i - 3];
            dp[i] -= dp[i] >= moder ? moder : 0;
        }
    }
    int ans = 1;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        if (s[i] == 'm' || s[i] == 'w'){
            puts("0");
            return 0;
        }
    }
    int pre = -1;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1 || s[i] != s[i + 1]){
            if (s[i] == 'u' || s[i] == 'n'){
                ans = 1ll * ans * dp[i - pre] % moder;
            }
            pre = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}