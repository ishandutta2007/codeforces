#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-9;
bool eq(double x, double y)
{
    return fabs(x - y) < eps;
}

const int N = 1010;
double g[N][N];
double ans[N];
bool used[N];
int n;
double q[N];

void add(int v)
{
    used[v] = 1;
    for (int u = 0; u < n; u++)
    {
        if (used[u]) continue;
        ans[u] += q[u] * g[u][v] * (ans[v] / (1 - q[v]));
        q[u] *= 1 - g[u][v];
    }
    return;
}

int getV()
{
    int w = -1;
    for (int v = 0; v < n; v++)
    {
        if (used[v]) continue;
        if (eq(q[v], 1)) continue;
        if (w == -1 || ans[w] / (1 - q[w]) > ans[v] / (1 - q[v]))
            w = v;
    }
    return w;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &g[i][j]);
            g[i][j] /= 100.;
        }
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
        q[i] = 1;
    for (int i = 0; i < n - 1; i++)
        ans[i] = 1;
    add(n - 1);
    while(!used[0])
        add(getV());
    printf("%.13lf\n", ans[0] / (1 - q[0]));

    return 0;
}