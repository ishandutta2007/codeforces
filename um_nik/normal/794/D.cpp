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

const int N = 300300;
int n, m;
vector<int> g[N];
map<vector<int>, int> toId;
int id[N];
ll edForId[N];
ll idSz[N];
set<pii> edges;
vector<int> G[N];

bool used[N];
int ord[N];
int revOrd[N];
int ordSz;

void dfs(int v)
{
    used[v] = 1;
    ord[ordSz] = v;
    revOrd[v] = ordSz;
    ordSz++;
    for (int u : G[v])
        if (!used[u])
            dfs(u);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    ll oldM = m;
    while(m--)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    m = 0;
    for (int i = 0; i < n; i++)
    {
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end());
        if (toId.count(g[i]))
            id[i] = toId[g[i]];
        else
        {
            id[i] = m;
            toId[g[i]] = m;
            m++;
        }
        idSz[id[i]]++;
    }
    for (int v = 0; v < n; v++)
        for (int u : g[v])
            if (id[v] == id[u])
                edForId[id[v]]++;
/* 
    for (int i = 0; i < n; i++)
        printf("%d ", id[i]);
    printf("\n");
    for (int i = 0; i < m; i++)
        printf("%lld %lld\n", idSz[i], edForId[i]);
*/  
    for (int i = 0; i < m; i++)
    {
        if (idSz[i] * idSz[i] != edForId[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    if (m == 1)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("1 ");
        printf("\n");
        return 0;
    }

    for (int v = 0; v < n; v++)
        for (int u : g[v])
        {
            int V = id[v], U = id[u];
            if (V == U) continue;
            if (V > U) swap(V, U);
            if (edges.count(mp(V, U))) continue;
            edges.insert(mp(V, U));
            G[V].push_back(U);
            G[U].push_back(V);
        }

    int SUM = 0;
    for (int i = 0; i < m; i++)
        SUM += (int)G[i].size();
    if (SUM != 2 * m - 2)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        int deg = (int)G[i].size();
        if (deg != 1 && deg != 2)
        {
            printf("NO\n");
            return 0;
        }
    }

    int V = 0;
    while(V < m && (int)G[V].size() != 1) V++;
    if (V == m) throw;
    dfs(V);

    if (ordSz != m) throw;

    for (int i = 0; i < m - 1; i++)
        oldM -= idSz[ord[i]] * idSz[ord[i + 1]];
    for (int i = 0; i < m; i++)
        oldM -= (idSz[i] * (idSz[i] - 1)) / 2;

    if (oldM != 0)
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int v = 0; v < n; v++)
        printf("%d ", revOrd[id[v]] + 1);
    printf("\n");

    return 0;
}