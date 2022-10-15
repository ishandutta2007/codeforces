#include<cstring>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int n, k, modulo = 1000000007;
char a[2222];
long long dp[2222][2222], s[2222][2222];
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    memset(dp, 0, sizeof(dp));
    memset(s, 0, sizeof(s));
    dp[0][0] = 1;
    s[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int o = 1; i - o >= 0 and j - o * (n - i + 1) >= 0; o++)
                dp[i][j] = (dp[i][j] + dp[i - o][j - o * (n - i + 1)] * ('z' - a[i - 1])) % modulo;
            dp[i][j] = (dp[i][j] + s[i - 1][j] * (a[i - 1] - 'a')) % modulo;
            s[i][j] = (s[i - 1][j] + dp[i][j]) % modulo;
        }
    }
    printf("%d\n", (int)s[n][k]);
    fclose(stdin);
    return 0;
}