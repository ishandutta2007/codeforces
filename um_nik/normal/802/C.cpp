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

struct Edge
{
    int v, u;
    ll cap, cost;

    Edge() : v(), u(), cap(), cost() {}
    Edge(int _v, int _u, ll _cap, ll _cost) : v(_v), u(_u), cap(_cap), cost(_cost) {}
};

const ll INF1 = (ll)1e9;
const ll INF2 = (ll)1e15;
const int E = (int)4e4;
const int V = 200;
int S, T;
int n, k;
int a[V];
ll c[V];
Edge ed[E];
int edSz;
ll dist[V];
int par[V];

void addEdge(int v, int u, ll cap, ll cost)
{
    ed[edSz++] = Edge(v, u, cap, cost);
    ed[edSz++] = Edge(u, v, 0, -cost);
}

ll flow()
{
    for (int i = 0; i <= S; i++)
        dist[i] = INF2;
    dist[S] = 0;
    bool ch = true;
    while(ch)
    {
        ch = false;
        for (int i = 0; i < edSz; i++)
        {
            Edge e = ed[i];
            if (e.cap <= 0) continue;
            if (dist[e.v] == INF2) continue;
            ll w = dist[e.v] + e.cost;
            if (w >= dist[e.u]) continue;
            dist[e.u] = w;
            par[e.u] = i;
            ch = true;
        }
    }
    ll res = 0;
    int v = T;
    while(v != S)
    {
        int id = par[v];
        ed[id].cap--;
        ed[id ^ 1].cap++;
        res += ed[id].cost;
        v = ed[id].v;
    }
    return res;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        scanf("%lld", &c[i]);
    S = 2 * n;
    T = 2 * n - 1;
    for (int i = 0; i < n; i++)
        addEdge(2 * i, 2 * i + 1, 1, -INF1);
    for (int i = 0; i < 2 * n - 1; i++)
        addEdge(i, T, INF1, 0);
    addEdge(S, T, INF1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll w = (a[i] == a[j] ? 0 : c[a[j]]);
            addEdge(2 * i + 1, 2 * j, INF1, w);
        }
        addEdge(S, 2 * i, INF1, c[a[i]]);
    }

    ll ans = INF1 * n;
    for (int i = 0; i < k; i++)
        ans += flow();
    printf("%lld\n", ans);

    return 0;
}