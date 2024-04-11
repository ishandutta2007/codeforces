#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, u[2001], v[2001], dp[2002][11][11][11][11];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int dfs(int now, int pos, int a, int b, int c)
{
    if (dp[now][pos][a][b][c])
    {
        return dp[now][pos][a][b][c];
    }
    int minn = 1e9, &ret = dp[now][pos][a][b][c];
    if (now > n)
    {
        if (!a && !b && !c)
        {
            return 0;
        }
        if (a)
        {
            checkmin(minn, dfs(now, a, 0, b, c) + abs(pos - a) + 1);
        }
        if (b)
        {
            checkmin(minn, dfs(now, b, a, 0, c) + abs(pos - b) + 1);
        }
        if (c)
        {
            checkmin(minn, dfs(now, c, a, b, 0) + abs(pos - c) + 1);
        }
        return ret = minn;
    }
    if (a)
    {
        checkmin(minn, dfs(now, a, 0, b, c) + abs(pos - a) + 1);
    }
    if (b)
    {
        checkmin(minn, dfs(now, b, a, 0, c) + abs(pos - b) + 1);
    }
    if (c)
    {
        checkmin(minn, dfs(now, c, a, b, 0) + abs(pos - c) + 1);
    }
    if (a && b && c)
    {
        checkmin(minn, dfs(now + 1, v[now], a, b, c) + abs(pos - u[now]) + abs(u[now] - v[now]) + 2);
        checkmin(minn, dfs(now + 1, a, v[now], b, c) + abs(pos - u[now]) + abs(u[now] - a) + 2);
        checkmin(minn, dfs(now + 1, b, a, v[now], c) + abs(pos - u[now]) + abs(u[now] - b) + 2);
        checkmin(minn, dfs(now + 1, c, a, b, v[now]) + abs(pos - u[now]) + abs(u[now] - c) + 2);
    }
    else
    {
        if (!a)
        {
            checkmin(minn, dfs(now + 1, u[now], v[now], b, c) + abs(pos - u[now]) + 1);
        }
        else
        {
            if (!b)
            {
                checkmin(minn, dfs(now + 1, u[now], a, v[now], c) + abs(pos - u[now]) + 1);
            }
            else
            {
                checkmin(minn, dfs(now + 1, u[now], a, b, v[now]) + abs(pos - u[now]) + 1);
            }
        }
    }
    return ret = minn;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &u[i], &v[i]);
    }
    printf("%d", dfs(1, 1, 0, 0, 0));
    return 0;
}