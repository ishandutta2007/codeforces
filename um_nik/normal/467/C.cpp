#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e17;
int n;
int k, m;
ll a[5004];
ll sum[5004];
ll dp[5004][5004];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
        {
            if (dp[i][j] == -INF)
                continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j == k || i + m > n)
                continue;
            dp[i + m][j + 1] = max(dp[i + m][j + 1], dp[i][j] + sum[i + m] - sum[i]);
        }
    printf("%I64d\n", dp[n][k]);

    return 0;
}