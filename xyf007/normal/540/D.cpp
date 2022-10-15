#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    double a, b, c;
    node operator+(const node x) const
    {
        node s;
        s.a = a + x.a;
        s.b = b + x.b;
        s.c = c + x.c;
        return s;
    }
    node operator*(const double x) const
    {
        node s;
        s.a = a * x;
        s.b = b * x;
        s.c = c * x;
        return s;
    }
} dp[101][101][101];
int a, b, c;
bool vis[101][101][101];
node dfs(int a, int b, int c)
{
    if (vis[a][b][c])
    {
        return dp[a][b][c];
    }
    if (a && !b && !c)
    {
        return (node){1.0, 0.0, 0.0};
    }
    if (!a && b && !c)
    {
        return (node){0.0, 1.0, 0.0};
    }
    if (!a && !b && c)
    {
        return (node){0.0, 0.0, 1.0};
    }
    vis[a][b][c] = 1;
    int tot = a * b + b * c + c * a;
    node ret = (node){0.0, 0.0, 0.0};
    if (a && b)
    {
        ret = ret + dfs(a, b - 1, c) * (a * b / (1.0 * tot));
    }
    if (b && c)
    {
        ret = ret + dfs(a, b, c - 1) * (b * c / (1.0 * tot));
    }
    if (c && a)
    {
        ret = ret + dfs(a - 1, b, c) * (c * a / (1.0 * tot));
    }
    return dp[a][b][c] = ret;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &a, &b, &c);
    node ans = dfs(a, b, c);
    printf("%.11lf %.11lf %.11lf", ans.a, ans.b, ans.c);
    return 0;
}