#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, a[100001], dp[100001][2], ans;
int main()
{
    scanf("%d", &n);
    ans = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dp[i][0] = 1;
        if(i != 1 and a[i - 1] < a[i]) dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;
        if(i >= 3 and a[i - 2] + 1 < a[i]) dp[i][1] = max(dp[i][1], dp[i - 2][0] + 2);
        if(i >= 2) dp[i][1] = max(dp[i][1], 2);
        //printf("%d %d\n", dp[i][0], dp[i][1]);
        ans = max(ans, dp[i][0]);
        if(i != n) ans = max(ans, dp[i][0] + 1);
        ans = max(ans, dp[i][1]);
    }
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}