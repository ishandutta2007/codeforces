#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const ll INF = 1e15;

vvll g;
int n;

ll go() {
    vector<bool> used (n, false);
    vector<ll> min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            cout << "No MST!";
            exit(0);
        }
        
        used[v] = true;
//        if (sel_e[v] != -1)
//            cout << v << " " << sel_e[v] << endl;
        
        for (int to=0; to<n; ++to) if (!used[to])
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    ll res = 0;
    forn(i,0,n) res+=min_e[i];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nw,m;
    scanf("%d %d", &nw, &m);
    vector<pair<pi, int>> e;
    set<pi> es;
    int mxr = 0;
    forn(i,0,m) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        es.insert(mp(u,v));
        es.insert(mp(v,u));
        e.pb(mp(mp(u,v), w));
        mxr ^= w;
    }
    vvi comps;
    set<int> vv;
    forn(i,0,nw) vv.insert(i);
    while(!vv.empty()) {
        comps.pb(vi());
        int v = *vv.begin();
        vv.erase(v);
        comps.back().pb(v);
        int pt = 0;
        while(pt < comps.back().size()) {
            v = comps.back()[pt];
            int pk = comps.back().size();
            for(auto u : vv) if(es.find(mp(v, u)) == es.end()) {
                comps.back().pb(u);
            }
            forn(i,pk,comps.back().size()) vv.erase(comps.back()[i]);
            pt++;
        }
        
    }
    n = comps.size();
    g = vvll (n, vll(n, INF));
    vi maap(nw);
    forn(i,0,n) {
        for(auto x : comps[i]) maap[x] = i;
    }
    for(auto x : e) {
        int u = x.first.first;
        int v = x.first.second;
        ll w = x.second;
        int u2 = maap[u];
        int v2 = maap[v];
        if(u2 != v2) {
            g[u2][v2] = min(g[u2][v2], w);
            g[v2][u2] = g[u2][v2];
        }
    }
    ll res = go();
    if(nw > 700 || nw-n + m < nw*(nw-1)/2) {
        cout<<res;
        exit(0);
    }
    ll ans = res + mxr;
    n = nw;
    g = vvll(n, vll(n, INF));
    vpi miss;
    for(auto x : e) {
        int u = x.first.first;
        int v = x.first.second;
        ll w = x.second;
        g[u][v] = w;
        g[v][u] = w;
    }
    forn(i,0,n) forn(j,i+1,n) {
        if(g[i][j] == INF) {
            miss.pb(mp(i,j));
            g[i][j] = 0;
            g[j][i] = 0;
        }
    }
    for(auto x : miss) {
        int u = x.first;
        int v = x.second;
        g[u][v] = mxr;
        g[v][u] = mxr;
        ans = min(ans, go());
        g[u][v] = 0;
        g[v][u] = 0;
    }
    

    cout<<ans;
}