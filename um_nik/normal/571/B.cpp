#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)2e9 + 20;
const int N = 300300;
const int M = 5050;
int n, k;
int a[N];
int dp[2][M];
int m, p;
int g;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    g = n / k;
    p = n - k * g;
    m = k - p;
    for (int i = 0; i <= k; i++)
        dp[0][i] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j <= k; j++)
            dp[1][j] = -INF;
        for (int t = 0; t <= min(i, m); t++)
        {
            int pos = (i + 1) * g + (i - t);
            if (t < m)
                dp[1][t + 1] = max(dp[1][t + 1], dp[0][t] + a[pos] - a[pos - 1]);
            dp[1][t] = max(dp[1][t], dp[0][t] + a[pos + 1] - a[pos]);
        }
        for (int j = 0; j <= k; j++)
            dp[0][j] = dp[1][j];
    }
    int res = -dp[0][m - 1];
    if (p > 0)
        res = min(res, -dp[0][m]);
    res += a[n - 1] - a[0];
    printf("%d\n", res);

    return 0;
}