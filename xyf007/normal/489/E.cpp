#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
const double eps = 1e-8;
int n, L, a[1001], b[1001], pre[1001];
double dp[1001];
bool check(double x)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e18;
        for (int j = 0; j < i; j++)
        {
            if (dp[i] > dp[j] + sqrt(abs(a[i] - a[j] - L)) - b[i] * x)
            {
                dp[i] = dp[j] + sqrt(abs(a[i] - a[j] - L)) - b[i] * x;
                pre[i] = j;
            }
        }
    }
    return dp[n] <= 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    double l = 0.0, r = 1e18;
    while (l + eps < r)
    {
        double mid = (l + r) / 2.0;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    check(l);
    stack<int> ans;
    int now = n;
    while (now)
    {
        ans.push(now);
        now = pre[now];
    }
    while (!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}