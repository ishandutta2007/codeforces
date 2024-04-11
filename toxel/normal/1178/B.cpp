#include <bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

char s[N];
ll dp[N][3];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i < n; ++ i){
        if (s[i - 1] == 'v' && s[i] == 'v'){
            dp[i][0] = 1;
        }
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < n; ++ i){
        if (s[i] == 'o'){
            dp[i][1] = dp[i - 1][0];
        }
        dp[i][1] += dp[i - 1][1];
    }
    for (int i = 2; i < n; ++ i){
        if (s[i - 1] == 'v' && s[i] == 'v'){
            dp[i][2] = dp[i - 2][1];
        }
        dp[i][2] += dp[i - 1][2];
    }
    printf("%lld\n", dp[n - 1][2]);
    return 0;
}