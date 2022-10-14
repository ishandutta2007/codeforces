#include <omp.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
typedef long long ll;
using namespace std;
ll k,oz,w,l,r,i,j,k1,k2,dr,n,m, qt, qh, md, x,y,z;
string s,t;
ll ans;

vector < vector < pair<ll,ll> > > g;

    set < pair<ll,ll> > q;
vector<ll> d,  p;
vector <ll> res;
map <pair<ll,ll>,ll> edges, sht;
int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    ll s;
    cin >> n >> m;
    g.resize(n);
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        x--; y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
        edges[mp(x,y)] = edges[mp(y,x)] = i+1;
        sht[mp(x,y)] = sht[mp(y,x)] = z;
    }
    cin >> s;
    s--;
    d.resize(n);
    p.resize(n);
    for (i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            ll to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            } else
            if (d[v] + len == d[to])
            {
                if (len < sht[mp(to,p[to])])
                {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.insert (make_pair (d[to], to));
                }
            }
        }
}
    ll ans = 0;
    for (i = 0; i < n; i++)
        if (i != s)
        {
            res.push_back(edges[mp(i,p[i])]);
            ans += sht[mp(i,p[i])];
        }
    cout << ans << endl;
    for (i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}