#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

struct Edge
{
    int idx;
    int to;
    ll l;

    Edge() : idx(), to(), l() {}
    Edge(int _idx, int _to, ll _l) : idx(_idx), to(_to), l(_l) {}
};

struct Event
{
    ll x;
    int type;
    int id;

    Event() : x(), type(), id() {}
    Event(ll _x, int t, int _id) : x(_x), type(t), id(_id) {}

    bool operator < (const Event &e) const
    {
        if (x != e.x) return x < e.x;
        return type < e.type;
    }
};

const ll INF = (ll)1e16;
const int N = 100100;
int n, m;
ll ans[N];
ll d[2][N];
vector<Edge> g[2][N];
int S, T;
ll L;

void read()
{
    scanf("%d%d%d%d", &n, &m, &S, &T);
    S--;T--;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        ll l;
        scanf("%d%d%I64d", &v, &u, &l);
        v--;u--;
        g[0][v].push_back(Edge(i + 1, u, l));
        g[1][u].push_back(Edge(i + 1, v, l));
    }
    return;
}

set<pli> setik;

void dijkstra(int id, int V)
{
    setik.clear();
    for (int i = 0; i < n; i++)
        d[id][i] = INF;
    d[id][V] = 0;
    for (int i = 0; i < n; i++)
        setik.insert(mp(d[id][i], i));
    while(!setik.empty())
    {
        int v = setik.begin()->Y;
        setik.erase(setik.begin());
        for (Edge e : g[id][v])
        {
            int to = e.to;
            ll w = d[id][v] + e.l;
            if (d[id][to] <= w) continue;
            setik.erase(mp(d[id][to], to));
            d[id][to] = w;
            setik.insert(mp(d[id][to], to));
        }
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    dijkstra(0, S);
    dijkstra(1, T);
    /*
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            printf("d[%d][%d] = %lld\n", i, j, d[i][j]);
    */
    L = d[0][T];
    vector<Event> ev;
    for (int v = 0; v < n; v++)
        for (Edge e : g[0][v])
        {
            int u = e.to;
            if (d[0][v] + e.l + d[1][u] > L) continue;
            ev.push_back(Event(d[0][v], 1, e.idx));
            ev.push_back(Event(d[0][v] + e.l, 0, e.idx));
        }
    for (int i = 1; i <= m; i++)
        ans[i] = INF;
    int bal = 0;
    sort(ev.begin(), ev.end());
    for (int i = 0; i < (int)ev.size(); i++)
    {
        Event e = ev[i];
        if (e.type == 0)
            bal--;
        else
        {
            if (bal == 0 && ev[i + 1].x != ev[i].x)
                ans[e.id] = 0;
            bal++;
        }
    }
    for (int v = 0; v < n; v++)
        for (Edge e : g[0][v])
        {
            int u = e.to;
            ll x = L - 1 - d[0][v] - d[1][u];
            if (x > 0 && ans[e.idx] != 0) ans[e.idx] = e.l - x;
        }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 0)
            printf("YES\n");
        else if (ans[i] == INF)
            printf("NO\n");
        else
            printf("CAN %I64d\n", ans[i]);
    }

    return 0;
}