/*
    Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int oo = 1000000010;
const int V = 100100;
const int P = 1000000007;
int dp[V][2][3], n;
char s[V];
int main()
{
    while(~scanf("%d", &n))
    {
        scanf("%s", s);
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 3; ++k)
                dp[i][j][k] = -oo;
        dp[0][s[0] - '0'][0] = 1;
        dp[0][(s[0] - '0') ^ 1][1] = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 3; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            int id = s[i] - '0';
            for(int k = 0; k < 3; ++k)
            {
                dp[i][id][k] = max(dp[i][id][k], dp[i - 1][id ^ 1][k] + 1);
                if(k != 0) dp[i][id][k] = max(dp[i][id][k], dp[i - 1][id][k - 1] + 1);
            }
        }
        int ans = 0;
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 3; ++k)
                ans = max(ans, dp[n - 1][j][k]);
        printf("%d\n", ans);
    }
    return 0;
}