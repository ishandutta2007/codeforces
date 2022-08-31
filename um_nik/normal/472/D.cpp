#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 1000;
int n;
const int N = 2010;
int a[N][N];
ll d[N][N];
vector<pii> g[N];
int p[N];
bool u[N];
int h[N];
int par[N][20];
ll dist[N][20];
bool used[N];

void badEnd()
{
    printf("NO\n");
    exit(0);
}

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int u = g[v][i].first;
        ll w = (ll)g[v][i].second;
        if (used[u])
            continue;
        h[u] = h[v] + 1;
        par[u][0] = v;
        dist[u][0] = w;
        for (int i = 1; i < 15; i++)
        {
            if (par[u][i - 1] == -1)
            {
                par[u][i] = -1;
                continue;
            }
            par[u][i] = par[ par[u][i - 1] ][i - 1];
            if (par[u][i] == -1)
                continue;
            dist[u][i] = dist[u][i - 1] + dist[ par[u][i - 1] ][i - 1];
        }
        dfs(u);
    }
    return;
}

int up(int v, int dh)
{
    for (int k = 14; k >= 0; k--)
    {
        if (dh < (1 << k))
            continue;
        v = par[v][k];
        dh -= 1 << k;
    }
    return v;
}

int lca(int v, int u)
{
    if (h[v] > h[u])
        swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u)
        return v;
    for (int k = 14; k >= 0; k--)
    {
        if (par[v][k] != par[u][k])
        {
            v = par[v][k];
            u = par[u][k];
        }
    }
    return par[v][0];
}

ll distUp(int v, int dh)
{
    ll ans = 0LL;
//  printf("v = %d, dh = %d\n", v, dh);
    for (int k = 14; k >= 0; k--)
    {
        if (dh < (1 << k))
            continue;
        dh -= 1 << k;
        ans += dist[v][k];
        v = par[v][k];
    }
//  cout << "ans = " << ans << endl;
    return ans;
}

ll getDist(int v, int u)
{
    int pp = lca(v, u);
    return distUp(v, h[v] - h[pp]) + distUp(u, h[u] - h[pp]);
}

void solve()
{
    for (int i = 0; i < 15; i++)
    {
        par[0][i] = -1;
        h[i] = 0;
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            d[i][j] = getDist(i, j);
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << ' ';
        cout << endl;
    }
    */
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        if (a[i][i] != 0)
            badEnd();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i] || a[i][j] == 0)
                badEnd();

    u[0] = 1;
    for (int i = 1; i < n; i++)
        p[i] = 0;
    for (int it = 1; it < n; it++)
    {
        int md = INF;
        int v = -1;
        for (int i = 0; i < n; i++)
        {
            if (u[i])
                continue;
            if (a[i][p[i]] < md)
            {
                md = a[i][p[i]];
                v = i;
            }
        }
        g[v].push_back( mp(p[v], md) );
        g[p[v]].push_back( mp(v, md) );

        u[v] = 1;
        for (int i = 0; i < n; i++)
        {
            if (u[i])
                continue;
            if (a[i][v] < a[i][p[i]])
                p[i] = v;
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        printf("v = %d, sz = %d\n", i, (int)g[i].size());
        for (int j = 0; j < (int)g[i].size(); j++)
        {
            printf("%d %d\n", g[i][j].first, g[i][j].second);
        }
    }
    */
    solve();

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != d[i][j])
                badEnd();
    printf("YES\n");

    return 0;
}