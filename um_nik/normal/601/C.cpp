#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 103;
const int M = 1002;
const int C = N * M;
double dp[N][C];
double sum[N][C];
int n, m;
int a[N];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    if (m == 1)
    {
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dp[0][0] = 1;
    for (int i = 1; i < C; i++)
        sum[0][i] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int x = 1; x < C; x++)
        {
            dp[i + 1][x] = (sum[i][x] - sum[i][max(x - m, 0)] - (x < a[i] ? 0 : dp[i][x - a[i]])) / (m - 1);
            sum[i + 1][x] = sum[i + 1][x - 1] + dp[i + 1][x - 1];
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    double ans = sum[n][s];
    printf("%.13lf\n", ans * (m - 1) + 1);

    return 0;
}