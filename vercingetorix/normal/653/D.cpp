#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 50; //  
const int INF = 1000000000; // -

struct edge {
    int a, b;
    ll cap,flow;
};

int n, m,s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void clear_all() {
    forn(i,0,MAXN) {
        d[i]=0;
        ptr[i]=0;
        q[i]=0;
        g[i].clear();
    }
    e.clear();
}

void add_edge (int a, int b, ll cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

ll dfs (int v, ll flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        ll pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (1) {
            ll pushed = dfs (s, INF);
            flow += pushed;
            if(pushed==0) break;
        }
    }
    return flow;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k,bears;
    //string s;
    ll ans = 0;
   
    cin >> n >> m >> bears;
    vpi edges;
    vll w;
    forn(i,0,m) {
        int x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        edges.pb(mp(x,y));
        w.pb(c);
    }
    s=0;
    t=n-1;
    double wl = 0;
    double wr = 1000001;
    int it = 100;
    while(it--) {
        double wm = (wl+wr)/2;
        //if(wm==0) {
        //    break;
        //}
        clear_all();
        forn(i,0,m) {
            add_edge(edges[i].first, edges[i].second, (ll)((double)w[i]/wm));
        }
        if(dinic() >= bears) wl=wm;
        else wr=wm;
    }
    printf("%.10lf", wl*bears);
    
    //cout<<ans;
}