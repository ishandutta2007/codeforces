#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
double dp[1001][1001];
double dfs(int a, int b)
{
    if (!a)
    {
        return 0.0;
    }
    if (b == 0)
    {
        return 1.0;
    }
    if (dp[a][b])
    {
        return dp[a][b];
    }
    double ret = 0;
    ret += 1.0 * a / (a + b);
    if (b == 2)
    {
        ret += 1.0 * b / (a + b) * (b - 1) / (a + b - 1) * dfs(a - 1, b - 2);
    }
    else
    {
        if (b >= 3)
        {
            ret += 1.0 * b / (a + b) * (b - 1) / (a + b - 1) * (1.0 * a / (a + b - 2) * dfs(a - 1, b - 2) + 1.0 * (b - 2) / (a + b - 2) * dfs(a, b - 3));
        }
    }
    return dp[a][b] = ret;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    printf("%.11lf", dfs(n, m));
    return 0;
}