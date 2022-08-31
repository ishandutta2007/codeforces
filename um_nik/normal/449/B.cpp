#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define x first
#define y second
#define mp make_pair

const ll INF = (ll)(1e18);
int n, m, k;
vector<pli> g[100100];
set<pli> a;
ll d[100100];
ll c[100100];
int ans = 0;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        c[i] = d[i] = INF;
    d[0] = 0LL;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll z;
        scanf("%d%d%I64d", &x, &y, &z);
        x--;
        y--;
        g[x].push_back( mp(z, y) );
        g[y].push_back( mp(z, x) );
    }
    ans = k;
    for (int i = 0; i < k; i++)
    {
        int x;
        ll z;
        scanf("%d%I64d", &x, &z);
        x--;
        c[x] = min(c[x], z);
    }
    for (int i = 0; i < n; i++)
    {
        a.insert( mp(d[i], i) );
        if (c[i] != INF)
            a.insert( mp(c[i], i) );
    }
    while (!a.empty())
    {
        int v = a.begin()->y;
        ll z = a.begin()->x;
        a.erase( a.begin() );
        if (z < d[v])
            ans--;
        d[v] = min(z, d[v]);
        for (int i = 0; i < (int)g[v].size(); i++)
        {
            int to = g[v][i].y;
            ll w = g[v][i].x;
            if (d[to] > d[v] + w)
            {
                a.erase( a.find( mp( d[to], to ) ) );
                d[to] = d[v] + w;
                a.insert( mp(d[to], to) );
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}