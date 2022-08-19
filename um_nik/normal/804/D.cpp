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

const int INF = (int)1e6;
const int N = (int)1e5 + 5;
vector<int> g[N];
int dist[N];
int q[N];
int topQ;
int n, m, Q;
int sz[N];
vector<int> a[N];
vector<ll> b[N];
int d[N];
int d2[N];
int col[N];
map<pii, ll> mapchik;

void read()
{
    scanf("%d%d%d", &n, &m, &Q);
    while(m--)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    m = 0;
    return;
}

void BFS(int v)
{
    while(topQ > 0)
    {
        topQ--;
        dist[q[topQ]] = INF;
    }
    dist[v] = 0;
    q[topQ++] = v;
    for (int k = 0; k < topQ; k++)
    {
        v = q[k];
        for (int u : g[v])
        {
            if (dist[u] > dist[v] + 1)
            {
                dist[u] = dist[v] + 1;
                q[topQ++] = u;
            }
        }
    }
    return;
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        col[i] = -1;
        dist[i] = INF;
        d2[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (col[i] != -1) continue;
        BFS(i);
        for (int j = 0; j < topQ; j++)
            col[q[j]] = m;
        sz[m] = topQ;
        BFS(q[topQ - 1]);
        for (int j = 0; j < topQ; j++)
            d2[q[j]] = max(d2[q[j]], dist[q[j]]);
        d[m] = dist[q[topQ - 1]];
        a[m].resize(d[m] + 1);
        for (int j = 0; j <= d[m]; j++)
            a[m][j] = 0;
        b[m].resize(d[m] + 1);
        for (int j = 0; j <= d[m]; j++)
            b[m][j] = 0;
        BFS(q[topQ - 1]);
        for (int j = 0; j < topQ; j++)
        {
            int v = q[j];
            d2[v] = max(d2[v], dist[v]);
            a[m][d2[v]]++;
        }
        b[m][d[m]] = (ll)a[m][d[m]] * d[m];
        for (int j = d[m]; j > 0; j--)
        {
            b[m][j - 1] = b[m][j] + (ll)a[m][j - 1] * (j - 1);
            a[m][j - 1] += a[m][j];
        }
        m++;
    }
    return;
}

void query()
{
    int v, u;
    scanf("%d%d", &v, &u);
    v = col[v - 1];
    u = col[u - 1];
    if (v == u)
    {
        printf("-1\n");
        return;
    }
    if (v > u) swap(v, u);
    pii ttt = mp(v, u);
    if (mapchik.count(ttt))
    {
        printf("%.12lf\n", (double)mapchik[ttt] / sz[v] / sz[u]);
        return;
    }
    if (d[v] > d[u]) swap(v, u);
    ll ans = 0;
    int D = max(d[v], d[u]);
    for (int k = 0; k <= d[v]; k++)
    {
        int p = D - k;
        ll cur = a[v][k] - (k < d[v] ? a[v][k + 1] : 0);
        if (p <= d[u])
            ans += (b[u][p] + (ll)a[u][p] * (k + 1)) * cur;
        ans += cur * D * (sz[u] - a[u][p]);
    }
    mapchik[ttt] = ans;
    printf("%.12lf\n", (double)ans / sz[v] / sz[u]);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    solve();
    while(Q--)
        query();

    return 0;
}