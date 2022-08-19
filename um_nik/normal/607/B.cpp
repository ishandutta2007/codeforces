#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = (int)1e5;
const int N = 520;
int n;
int a[N];
int dp[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int len = 0; len <= n; len++)
        for (int l = 0; l + len <= n; l++)
        {
            if (len <= 1)
                dp[l][l + len] = 1;
            else if (dp[l + 1][l + len - 1] == 1 && a[l] == a[l + len - 1])
                dp[l][l + len] = 1;
            else
                dp[l][l + len] = INF;
        }
    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++)
        {
            if (dp[l][l + len] == 1) continue;
            for (int k = l + 1; k < l + len; k++)
                dp[l][l + len] = min(dp[l][l + len], dp[l][k] + dp[k][l + len]);
            if (a[l] != a[l + len - 1]) continue;
            dp[l][l + len] = min(dp[l][l + len], dp[l + 1][l + len - 1]);
        }
    printf("%d\n", dp[0][n]);

    return 0;
}