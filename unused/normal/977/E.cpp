#include <bits/stdc++.h>
using namespace std;

int deg[200005];
int par[200005];
int gs[200005];

int gp(int t)
{
    return t == par[t] ? t : par[t] = gp(par[t]);
}

void mg(int a, int b)
{
    par[gp(a)] = gp(b);
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        mg(a, b);
        deg[a]++; deg[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        int p = gp(i);
        if (gs[p] == -1) continue;
        if (deg[i] == 2) ++gs[p];
        else gs[p] = -1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (gs[i] > 0) ++ans;
    }
    printf("%d\n", ans);
}