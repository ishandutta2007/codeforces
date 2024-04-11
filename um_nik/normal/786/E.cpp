#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)2e4 + 10;
const int V = (int)1e6;
const int E = (int)5e6;
const int LOG = 15;
const int INF = (int)1e9 + 3;

struct Edge
{
    int v, to, cap;

    Edge() : v(), to(), cap() {}
    Edge (int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap) {}
};
Edge ed[E];
int edSz;

int n;
vector<int> g[V];
int idx[V];
int dist[V];
int q[V];
int topQ;
int s, t;

void addEdge(int v, int u, int cap)
{
    ed[edSz] = Edge(v, u, cap);
    g[v].push_back(edSz++);
    ed[edSz] = Edge(u, v, 0);
    g[u].push_back(edSz++);
    return;
}

vector<int> T[N];
int h[N];
int par[N][LOG][2];
int readEdges[N][2];
int vertices, citizens;

void dfsTree(int v)
{
    for (int u : T[v])
    {
        if (h[u] != -1) continue;
        h[u] = h[v] + 1;
        par[u][0][0] = v;
        par[u][0][1] = n++;
        for (int k = 1; k < LOG; k++)
        {
            int w = par[u][k - 1][0];
            if (par[w][k - 1][0] == -1) break;
            par[u][k][0] = par[w][k - 1][0];
            par[u][k][1] = n++;
            addEdge(par[u][k][1], par[u][k - 1][1], INF);
            addEdge(par[u][k][1], par[w][k - 1][1], INF);
        }
        dfsTree(u);
    }
    return;
}

void edgesToPath(int u, int v, int dh)
{
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        addEdge(u, par[v][k][1], INF);
        v = par[v][k][0];
    }
    return;
}

int up(int v, int dh)
{
    for (int k = LOG - 1; k >= 0; k--)
    {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        v = par[v][k][0];
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
        if (par[v][k][0] != par[u][k][0])
        {
            v = par[v][k][0];
            u = par[u][k][0];
        }
    }
    return par[v][0][0];
}

void read()
{
    scanf("%d%d", &vertices, &citizens);
    for (int i = 1; i < vertices; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        readEdges[i - 1][0] = v;
        readEdges[i - 1][1] = u;
        T[v].push_back(u);
        T[u].push_back(v);
    }
    for (int i = 0; i < vertices; i++)
    {
        h[i] = -1;
        for (int k = 0; k < LOG; k++)
            par[i][k][0] = par[i][k][1] = -1;
    }
    h[0] = 0;
    dfsTree(0);
    for (int i = 0; i < citizens; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        int w = LCA(v, u);
        edgesToPath(n + i, v, h[v] - h[w]);
        edgesToPath(n + i, u, h[u] - h[w]);
    }
    n += citizens;
    s = n++;
    t = n++;
    for (int i = 0; i < citizens; i++)
        addEdge(s, n - 2 - citizens + i, 1);
    for (int v = 1; v < vertices; v++)
        addEdge(par[v][0][1], t, 1);
    return;
}

bool BFS()
{
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[s] = 0;
    topQ = 0;
    q[topQ++] = s;
    for (int i = 0; i < topQ; i++)
    {
        int v = q[i];
        for (int eid : g[v])
        {
            Edge e = ed[eid];
            if (e.cap == 0) continue;
            int to = e.to;
            if (dist[to] <= dist[v] + 1) continue;
            dist[to] = dist[v] + 1;
            q[topQ++] = to;
        }
    }
    return dist[t] < INF;
}

int DFS(int v, int flow)
{
    if (flow == 0 || v == t) return flow;
    int res = 0;
    for (int &i = idx[v]; i < (int)g[v].size(); i++)
    {
        int eid = g[v][i];
        Edge e = ed[eid];
        int to = e.to;
        if (e.cap == 0 || dist[to] != dist[v] + 1) continue;
        int df = DFS(to, min(e.cap, flow));
        res += df;
        flow -= df;
        ed[eid].cap -= df;
        ed[eid ^ 1].cap += df;
        if (flow == 0) return res;
    }
    return res;
}

int Flow()
{
    int res = 0;
    while(BFS())
    {
        for (int i = 0; i < n; i++)
            idx[i] = 0;
        res += DFS(s, INF);
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    //cerr << "readed" << endl;
    int ans = Flow();
    //cerr << ans << endl;
    vector<int> toCit, toGuard;
    for (int i = 0; i < citizens; i++)
    {
        int v = n - 2 - citizens + i;
        if (dist[v] == INF)
            toCit.push_back(i + 1);
    }
    for (int i = 0; i < vertices - 1; i++)
    {
        int v = readEdges[i][0], u = readEdges[i][1];
        if (h[v] < h[u]) swap(v, u);
        v = par[v][0][1];
        if (dist[v] < INF)
            toGuard.push_back(i + 1);
    }
    if (ans != (int)toCit.size() + (int)toGuard.size()) throw;
    printf("%d\n", ans);
    printf("%d", (int)toCit.size());
    for (int x : toCit)
        printf(" %d", x);
    printf("\n%d", (int)toGuard.size());
    for (int x : toGuard)
        printf(" %d", x);
    printf("\n");

    return 0;
}