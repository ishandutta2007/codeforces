#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)1e7;
const int N = (int)2e4 + 100;
const int C = 303;
int n;
int m;
int a[N];
int dp[C];
int b[N], c[N];
int l[C], r[C], cnt[C];

void solveSmall()
{
    for (int i = 0; i < n * m; i++)
        a[i] = a[i % n];
     for (int i = 0; i < n * m; i++)
     {
         for (int j = a[i]; j >= 0; j--)
             dp[a[i]] = max(dp[a[i]], dp[j] + 1);
     }
     int ans = 0;
     for (int i = 0; i < C; i++)
         ans = max(ans, dp[i]);
     printf("%d\n", ans);
     return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (m <= 2 * n + 4)
    {
        solveSmall();
        return 0;
    }
    for (int i = 0; i < n * n; i++)
        a[i] = a[i % n];
    for (int i = 0; i < C; i++)
        dp[i] = 0;
    for (int i = 0; i < n * n; i++)
    {
        for (int j = a[i]; j >= 0; j--)
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
        b[i] = dp[a[i]];
    }
    for (int i = 0; i < C; i++)
        dp[i] = 0;
    for (int i = n * n - 1; i >= 0; i--)
    {
        for (int j = a[i]; j < C; j++)
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
        c[i] = dp[a[i]];
    }
    for (int i = 0; i < C; i++)
        l[i] = N;
    for (int i = 0; i < n; i++)
    {
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = i;
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int x = 0; x < C; x++)
    {
        if (l[x] == N) continue;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int y = cnt[x] * (m - i - (n - j - 1)) - 2;
                ans = max(ans, y + b[i * n + l[x]] + c[j * n + r[x]]);
            }
    }
    printf("%d\n", ans);

    return 0;
}