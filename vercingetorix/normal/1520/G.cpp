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
#include <queue>
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
const int INF = 1e9;
vvi g;
vi vis;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nw,m,w;
    scanf("%d %d %d", &nw, &m, &w);
    vvi a(nw, vi(m));
    forn(i,0,nw) forn(j,0,m) scanf("%d", &a[i][j]);
    
    int n = nw*m;
    g = vvi (n);
    //    forn(i,0,nw) forn(j,0,m) {
    //        if(a[i][j] > 0) {
    //            g[i*m+j].pb(mp(m*nw, a[i][j]));
    //            g[m*nw].pb(mp(i*m+j, a[i][j]));
    //        }
    //    }
    forn(i,0,nw) forn(j,0,m-1) {
        if(a[i][j] != -1 && a[i][j+1] != -1) {
            g[i*m+j].pb(i*m+j+1);
            g[i*m+j+1].pb(i*m+j);
        }
    }
    forn(i,0,nw-1) forn(j,0,m) {
        if(a[i][j] != -1 && a[i+1][j] != -1) {
            g[i*m+j].pb(i*m+m+j);
            g[i*m+j+m].pb(i*m+j);
        }
    }
    int st = 0;
    int en = m*nw-1;
    map<int, ll> toportal;
    const ll INF2 = 1e18;
    ll ans = INF2;
    for(int ha = 0; ha<=en; ha += en) {
        int s = ha;
        vector<int> d (n, INF),  p (n);
        d[s] = 0;
        deque<int> q;
        q.pb(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop_front();
            for(auto u : g[v]) if(d[u] == INF) {
                d[u] = d[v]+1;
                q.pb(u);
            }
        }
//        priority_queue < pi > q;
//        q.push (make_pair (0, s));
//        while (!q.empty()) {
//            int v = q.top().second,  cur_d = -q.top().first;
//            q.pop();
//            if (cur_d > d[v])  continue;
//
//            for (size_t j=0; j<g[v].size(); ++j) {
//                int to = g[v][j];
//                if (d[v] + 1 < d[to]) {
//                    d[to] = d[v] + 1;
//                    p[to] = v;
//                    q.push (make_pair (-d[to], to));
//                }
//            }
//        }
        ll best = INF2;
        forn(i,0,nw) forn(j,0,m) if(a[i][j] > 0 && d[i*m+j] != INF) best = min(best, ll(d[i*m+j])*w + a[i][j]);
        toportal[ha] = best;
        if(d[en-ha] != INF) ans = min(ans, (ll)d[en-ha]*w);
    }
    ans = min(ans, toportal[en] + toportal[st]);
    //    ll ans = d[m*nw-1];
    if (ans == INF2) ans = -1;
    cout<<ans
    ;
}