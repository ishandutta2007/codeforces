#include <iostream>
using namespace std;

int n, m;
double a[1000];
int x, y;
double ans, t;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    while (m--)
    {
        scanf("%d%d%lf", &x, &y, &t);
        x--;
        y--;
        ans = max(ans, (a[x] + a[y]) / t);
    }
    printf("%.12lf\n", ans);
    return 0;
}