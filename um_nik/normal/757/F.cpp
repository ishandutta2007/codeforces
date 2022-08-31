#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define mp make_pair

const ll INF = (ll)1e18;
const int N = 200200;
const int LOG = 18;
int n, m;
vector<pli> G[N];
set<pli> setik;
ll dist[N];
pli a[N];
int b[N];
vector<int> g[N];
vector<int> rg[N];
int par[N][LOG];
int h[N];
int sz[N];
int S;

void dijkstra()
{
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[S] = 0;
    for (int i = 0; i < n; i++)
        setik.insert(mp(dist[i], i));
    while(!setik.empty())
    {
        int v = setik.begin()->second;
        if (dist[v] == INF) break;
        setik.erase(setik.begin());
        for (pli e : G[v])
        {
            int u = e.second;
            ll w = dist[v] + e.first;
            if (dist[u] <= w) continue;
            setik.erase(mp(dist[u], u));
            dist[u] = w;
            setik.insert(mp(dist[u], u));
        }
    }
    return;
}

int up(int v, int dh)
{
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        v = par[v][k];
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (par[v][k] != par[u][k])
        {
            v = par[v][k];
            u = par[u][k];
        }
    }
    return par[v][0];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &S);
    S--;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        ll w;
        scanf("%d%d%lld", &v, &u, &w);
        v--;u--;
        G[v].push_back(mp(w, u));
        G[u].push_back(mp(w, v));
    }
    dijkstra();

    m = 0;
    for (int i = 0; i < n; i++)
        if (dist[i] != INF)
            a[m++] = mp(dist[i], i);
    sort(a, a + m);
    for (int i = 0; i < n; i++)
        b[i] = -1;
    for (int i = 0; i < m; i++)
        b[a[i].second] = i;

    for (int v = 0; v < n; v++)
    {
        if (b[v] == -1) continue;
        for (pli e : G[v])
        {
            int u = e.second;
            if (b[u] == -1) throw;
            if (dist[v] + e.first == dist[u])
            {
                //g[b[v]].push_back(b[u]);
                rg[b[u]].push_back(b[v]);
            }
        }
    }
    
    h[0] = 0;
    for (int i = 0; i < LOG; i++)
        par[0][i] = -1;
    for (int i = 1; i < m; i++)
    {
        int v = -1;
        for (int u : rg[i])
        {
            if (v == -1)
                v = u;
            else
                v = LCA(v, u);
        }
        h[i] = h[v] + 1;
        par[i][0] = v;
        for (int k = 1; k < LOG; k++)
        {
            int w = par[i][k - 1];
            if (w == -1)
                par[i][k] = -1;
            else
                par[i][k] = par[w][k - 1];
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        sz[i]++;
        if (par[i][0] != -1)
            sz[par[i][0]] += sz[i];
    }
    int ans = 0;
    for (int i = 1; i < m; i++)
        ans = max(ans, sz[i]);
    printf("%d\n", ans);

    return 0;
}