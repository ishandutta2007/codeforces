#include<bits/stdc++.h>

const int N = 1 << 3;

int dp[N];
char s[N];

int main(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d%s", &x, s);
        int len = strlen(s);
        int bit = 0;
        for (int j = 0; j < len; ++ j){
            bit |= 1 << s[j] - 'A';
        }
        for (int j = N - 1; j >= 0; -- j){
            if (dp[j] == -1) continue;
            if (dp[j | bit] == -1 || dp[j | bit] > dp[j] + x){
                dp[j | bit] = dp[j] + x;
            }
        }
    }
    printf("%d\n", dp[N - 1]);
}