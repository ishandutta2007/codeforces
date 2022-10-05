#include <bits/stdc++.h>

const int N = 3010;
const int moder = 998244353;

int dp[N][N][2];
char s[N], t[N];

void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}

int main(){
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    dp[n][0][0] = 1;
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < N; ++ j){
            for (int k = 0; k < 2; ++ k){
                if (!dp[i + 1][j][k]){
                    continue;
                }
                int pos = j;
                if (pos >= m || s[i] == t[pos]){
                    add(dp[i][j + 1][1], dp[i + 1][j][k]);
                }
                pos = n - i - 1 - j;
                pos = n - 1 - pos;
                if (pos >= m || s[i] == t[pos]){
                    add(dp[i][j][1], dp[i + 1][j][k]);
                    if (k == 0 && pos >= m){
                        add(dp[i][j][0], dp[i + 1][j][0]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        add(ans, dp[0][i][0]);
        add(ans, dp[0][i][1]);
    }
    printf("%d\n", ans);
    return 0;
}