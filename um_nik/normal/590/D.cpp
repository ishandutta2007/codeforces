#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)1e9;
const int N = 152;
const int M = N * N;
int n, k, s;
int dp[N][M];
int a[N];
int b[N];
int m;
int ans = INF;
int c[N][M], d[N][M];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &m, &k, &s);
    s = min(s, m * (m - 1) / 2);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < k; i++)
        a[i] = b[k - 1 - i];
    
    n = k;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            dp[i][j] = -INF;
    for (int j = 0; j <= s; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j >= 0; j--)
            for (int x = 0; x <= s; x++)
            {
                if (dp[j][x] == -INF) continue;
                if (x + i - j > s) continue;
                dp[j + 1][x + i - j] = max(dp[j + 1][x + i - j], dp[j][x] + a[i]);
            }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            c[i][j] = dp[i][j];

    n = m - k;
    for (int i = 0; i < n; i++)
        a[i] = b[k + i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            dp[i][j] = INF;
    for (int j = 0; j <= s; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j >= 0; j--)
            for (int x = 0; x <= s; x++)
            {
                if (dp[j][x] == INF) continue;
                if (x + i - j > s) continue;
                dp[j + 1][x + i - j] = min(dp[j + 1][x + i - j], dp[j][x] + a[i]);
            }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= s; j++)
            d[i][j] = dp[i][j];

    for (int i = 0; i <= min(k, m - k); i++)
    {
        int x = s - i * i;
        if (x < 0) break;
        for (int j = 0; j <= x; j++)
            ans = min(ans, d[i][j] - c[i][x - j]);
    }
    for (int i = 0; i < k; i++)
        ans += b[i];
    printf("%d\n", ans);

    return 0;
}