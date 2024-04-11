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
typedef pair<ll, int> pli;
#define mp make_pair

const ll INF = (ll)1e18;
const int N = 1 << 17;
int n, q, s;
vector<pli> g[3 * N];

void addEdge(int v, int u, ll w)
{
    g[v].push_back(mp(w, u));
    return;
}

void build()
{
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 2; j++)
        {
            int v = i;
            int u = 2 * i + j;
            if (u >= N)
            {
                addEdge(v, u + N, 0);
                addEdge(u + N, v + N, 0);
            }
            else
            {
                addEdge(v, u, 0);
                addEdge(u + N, v + N, 0);
            }
        }
}

void addFrom(int v, int a, int b, int l, int r, int u, ll w)
{
    if (l <= a && b <= r)
    {
        if (v >= N)
            addEdge(u, v + N, w);
        else
            addEdge(u, v, w);
        return;
    }
    if (r <= a || b <= l) return;
    int mid = (a + b) / 2;
    addFrom(2 * v, a, mid, l, r, u, w);
    addFrom(2 * v + 1, mid, b, l, r, u, w);
    return;
}
void addTo(int v, int a, int b, int l, int r, int u, ll w)
{
    if (l <= a && b <= r)
    {
        if (v >= N)
            addEdge(v + N, u, w);
        else
            addEdge(v + N, u, w);
        return;
    }
    if (r <= a || b <= l) return;
    int mid = (a + b) / 2;
    addTo(2 * v, a, mid, l, r, u, w);
    addTo(2 * v + 1, mid, b, l, r, u, w);
    return;
}

ll dist[3 * N];

void dijkstra(int V)
{
    set<pli> setik;
    for (int i = 0; i < 3 * N; i++)
        dist[i] = INF;
    dist[V] = 0;
    for (int i = 0; i < 3 * N; i++)
        setik.insert(mp(dist[i], i));
    while(!setik.empty())
    {
        int v = setik.begin()->second;
        setik.erase(setik.begin());
        for (pli e : g[v])
        {
            int to = e.second;
            ll w = dist[v] + e.first;
            if (dist[to] <= w) continue;
            setik.erase(mp(dist[to], to));
            dist[to] = w;
            setik.insert(mp(dist[to], to));
        }
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &q, &s);
    build();
    while(q--)
    {
        //cerr << q << endl;
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int v, u;
            ll w;
            scanf("%d%d%lld", &v, &u, &w);
            v += 2 * N;
            u += 2 * N;
            addEdge(v, u, w);
        }
        else if (t == 2)
        {
            int v, l, r;
            ll w;
            scanf("%d%d%d%lld", &v, &l, &r, &w);
            r++;
            addFrom(1, 0, N, l, r, 2 * N + v, w);
        }
        else
        {
            int v, l, r;
            ll w;
            scanf("%d%d%d%lld", &v, &l, &r, &w);
            r++;
            addTo(1, 0, N, l, r, 2 * N + v, w);
        }
    }
    dijkstra(s + 2 * N);
    for (int i = 2 * N + 1; i <= 2 * N + n; i++)
    {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}