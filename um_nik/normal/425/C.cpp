#include <iostream>
#include <vector>
using namespace std;

const int INF = 10000000;
int n, m;
int a[100100], b[100100];
int d[400];
int c[100100][302];
vector<int> g[100100];
int s, e, ans;

int bin_search (int v, int x)
{
    if ((int)g[v].size() == 0)
        return INF;
    if (g[v][(int)g[v].size() - 1] <= x)
        return INF;
    if (g[v][0] > x)
        return g[v][0];
    int r = (int)g[v].size() - 1;
    int l = 0;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (g[v][m] > x)
            r = m;
        else
            l = m;
    }
    return g[v][r];
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        g[b[i]].push_back(i);
    }
    d[0] = 0;
    for (int i = 1; i < 350; i++)
        d[i] = INF;
    for (int i = 1; i <= n; i++)
    {
        c[i][0] = 0;
        for (int k = 300; k > 0; k--)
        {
            if ((int)g[a[i]].size() == 0)
            {
                c[i][k] = INF;
                continue;
            }
            c[i][k] = bin_search(a[i], d[k - 1]);
            d[k] = min(d[k], c[i][k]);
        }
    }
    ans = 0;
    for (int k = 1; k < 301; k++)
    {
        s -= e;
        if (s < 0)
            break;
        for (int i = 1; i <= n; i++)
            if (s >= i + c[i][k])
            {
                ans = k;
                break;
            }
    }
    printf("%d\n", ans);
    //cin >> n;
    return 0;
}