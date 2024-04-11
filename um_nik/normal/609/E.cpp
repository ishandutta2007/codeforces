#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair
#define X first
#define Y second
const int N = 200200;
const int L = 18;
int n, m;

struct Edge
{
    int v, u;
    ll w;
    int id;

    Edge() : v(), u(), w(), id() {}

    void scan(int _id)
    {
        id = _id;
        scanf("%d%d%lld", &v, &u, &w);
        v--;u--;
    }

    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
};
Edge ed[N];
int par[N], sz[N];
vector<Edge> badEdges;
ll ans[N];
vector<pil> g[N];
ll W = 0;
int h[N];
int p[N][L];
ll d[N][L];

int getPar(int v)
{
    return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}
bool unite(int v, int u)
{
    v = getPar(v);
    u = getPar(u);
    if (v == u) return false;
    if (sz[v] < sz[u]) swap(v, u);
    sz[v] += sz[u];
    par[u] = v;
    return true;
}

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        ed[i].scan(i);
    return;
}

void addEdge(Edge e)
{
    g[e.v].push_back(mp(e.u, e.w));
    g[e.u].push_back(mp(e.v, e.w));
    return;
}

void buildMST()
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
    sort(ed, ed + m);
    for (int i = 0; i < m; i++)
    {
        if (unite(ed[i].v, ed[i].u))
        {
            addEdge(ed[i]);
            W += ed[i].w;
        }
        else
            badEdges.push_back(ed[i]);
    }
    return;
}

void dfs(int v)
{
    for (pil e : g[v])
    {
        int u = e.X;
        if (h[u] != -1) continue;
        h[u] = h[v] + 1;
        p[u][0] = v;
        d[u][0] = e.Y;
        for (int i = 1; i < L; i++)
        {
            if (p[u][i - 1] == -1)
            {
                p[u][i] = -1;
                d[u][i] = d[u][i - 1];
                continue;
            }
            int w = p[u][i - 1];
            p[u][i] = p[w][i - 1];
            d[u][i] = max(d[u][i - 1], d[w][i - 1]);
        }
        dfs(u);
    }
    return;
}

void buildLCA()
{
    for (int i = 0; i < n; i++)
        h[i] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < L; j++)
            p[i][j] = -1;
    h[0] = 0;
    dfs(0);
    return;
}

int up(int v, int dh)
{
    for (int k = L - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        v = p[v][k];
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = L - 1; k >= 0; k--)
    {
        if (p[v][k] != p[u][k])
        {
            v = p[v][k];
            u = p[u][k];
        }
    }
    return p[v][0];
}
int getMaxUp(int v, int dh)
{
    ll res = 0;
    for (int k = L - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        res = max(res, d[v][k]);
        v = p[v][k];
    }
    return res;
}
int getMax(int v, int u)
{
    int w = LCA(v, u);
    return max(getMaxUp(v, h[v] - h[w]), getMaxUp(u, h[u] - h[w]));
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    buildMST();
    buildLCA();
    for (Edge e : badEdges)
        ans[e.id] = e.w - getMax(e.v, e.u);
    for (int i = 0; i < m; i++)
        printf("%lld\n", W + ans[i]);

    return 0;
}