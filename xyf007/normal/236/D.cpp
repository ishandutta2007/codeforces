#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
double p[100001], dp[100001][3];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &p[i]);
    }
    double ans = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        dp[i][1] = (dp[i - 1][1] + 1) * p[i];
        dp[i][2] = (dp[i - 1][2] + 2 * dp[i - 1][1] + 1) * p[i];
        ans += dp[i - 1][2] * (1 - p[i]);
    }
    printf("%.10lf", ans);
    return 0;
}