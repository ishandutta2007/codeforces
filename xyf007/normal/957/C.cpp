#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, u, a[100001];
void checkmax(double &x, double y)
{
    if (x < y)
    {
        x = y;
    }
}
int main()
{
    scanf("%d%d", &n, &u);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    double ans = 0.0;
    for (int i = 0; i < n - 2; i++)
    {
        int x = a[i], y = a[i + 1], k = a[std::upper_bound(a, a + n, x + u) - a - 1];
        checkmax(ans, (k - y) / ((k - x) * 1.0));
    }
    if (ans < 1e-6)
    {
        printf("-1");
    }
    else
    {
        printf("%.9lf", ans);
    }
    return 0;
}//u