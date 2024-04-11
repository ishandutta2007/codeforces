#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int INF = (int)1e6 + 100;
const int L = 17;
const int N = 300100;
int n;
vector<int> g[N];
int p[N][L];
int h[N];
int tin[N], tout[N];
int dp[N][2];
int T;
int m;
vector<pii> a;
vector<int> G[N];
bool mark[N];

void dfs(int v)
{
    tin[v] = T++;
    for (int u : g[v])
    {
        if (h[u] != -1) continue;
        p[u][0] = v;
        for (int k = 1; k < L; k++)
        {
            int w = p[u][k - 1];
            if (w == -1)
            {
                p[u][k] = -1;
                continue;
            }
            p[u][k] = p[w][k - 1];
        }
        h[u] = h[v] + 1;
        dfs(u);
    }
    tout[v] = T++;
    return;
}

int up(int v, int dh)
{
    for (int k = L - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        v = p[v][k];
        dh -= 1 << k;
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = L - 1; k >= 0; k--)
        if (p[v][k] != p[u][k])
        {
            v = p[v][k];
            u = p[u][k];
        }
    return p[v][0];
}

void read()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    return;
}

void precalc()
{
    read();
    for (int i = 0; i < L; i++)
        p[0][i] = -1;
    for (int i = 0; i < n; i++)
        h[i] = -1;
    h[0] = 0;
    dfs(0);
/*
    for (int v = 0; v < n; v++)
        printf("h[%d] = %d\n", v, h[v]);
    for (int v = 0; v < n; v++)
        printf("tin[%d] = %d, tout[%d] = %d\n", v, tin[v], v, tout[v]);
*/
    return;
}

void solve()
{
    a.clear();
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int v;
        scanf("%d", &v);
        v--;
        mark[v] = true;
        a.push_back(mp(tin[v], v));
    }
    bool ok = false;
    for (int i = 0; !ok && i < m; i++)
    {
        int u = p[a[i].second][0];
        if (u == -1) continue;
        if (mark[u])
            ok = true;
    }
    if (ok)
    {
        printf("-1\n");
        for (int i = 0; i < m; i++)
            mark[a[i].second] = false;
        return;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m - 1; i++)
    {
        int v = LCA(a[i].second, a[i + 1].second);
        a.push_back(mp(tin[v], v));
    }
    for (int i = 0; i < m; i++)
    {
        int v = p[a[i].second][0];
        if (v == -1) continue;
        a.push_back(mp(tin[v], v));
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    m = (int)a.size();
    for (int i = 0; i < m; i++)
    {
        int v = a[i].second;
        int x = tin[v] + 1;
        while(true)
        {
            int pos = lower_bound(a.begin(), a.end(), mp(x, -1)) - a.begin();
            if (pos == m) break;
            int u = a[pos].second;
            if (tin[u] > tout[v]) break;
            G[v].push_back(u);
            x = tout[u] + 1;
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        int v = a[i].second;
        if (mark[v])
        {
            dp[v][0] = INF;
            dp[v][1] = 0;
            for (int u : G[v])
                dp[v][1] = min(INF, dp[v][1] + dp[u][0]);
        }
        else
        {
            int valBlock = 1;
            dp[v][0] = 0;
            dp[v][1] = INF;
            for (int u : G[v])
            {
                valBlock = min(INF, valBlock + min(dp[u][0], dp[u][1]));
                dp[v][1] = min(INF, min(dp[v][0] + dp[u][1], dp[v][1] + dp[u][0]));
                dp[v][0] = min(INF, dp[v][0] + dp[u][0]);
            }
            dp[v][0] = min(dp[v][0], valBlock);
        }
        dp[v][1] = min(dp[v][1], dp[v][0]);
    }
//  for (int i = 0; i < n; i++)
//      printf("dp[%d][0] = %d, dp[%d][1] = %d\n", i, dp[i][0], i, dp[i][1]);
    int v = a[0].second;
    printf("%d\n", dp[v][1]);
    for (int i = 0; i < m; i++)
    {
        v = a[i].second;
        mark[v] = false;
        G[v].clear();
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    precalc();
    int q;
    scanf("%d", &q);
    while(q--)
        solve();

    return 0;
}