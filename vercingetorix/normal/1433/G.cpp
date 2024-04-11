#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <queue>
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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])
//int d[1001][1001];
vvi d;
#define pb push_back
#define mp make_pair
const int INF =1e9;

//vi get(int u, int v) {
//    vi res;
//    if(p[u][v] != -1) {
//        int t = p[u][v];
//        for(auto x : get(u, t)) res.pb(x);
//        res.pb(t);
//        for(auto x : get(t,v)) res.pb(x);
//    }
//    return res;
//}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    cin>>n>>m>>k;
    vvi d(n, vi(n, INF));
//    forn(i,0,n) forn(j,0,n) d[i][j] = INF;

//    p=vvi (n, vi(n, -1));
    forn(i,0,n) d[i][i] = 0;
//    map<pi, int> g;
    map<pi, int> cnt;
    vpi e;
    vi h;
    ll cur = 0;
    vvpi g(n);
    forn(i,0,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        if(u>v) swap(u,v);
        e.pb(mp(u,v));
        h.pb(w);
        
//        d[u][v] = w;
//        d[v][u] = w;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
//    vector<int> d (n, INF),  p (n);
    
    forn(s,0,n) {
        d[s][s] = 0;
        priority_queue < pair<int,int> > q;
        q.push (make_pair (0, s));
        while (!q.empty()) {
            int v = q.top().second,  cur_d = -q.top().first;
            q.pop();
            if (cur_d > d[s][v])  continue;
            
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                len = g[v][j].second;
                if (d[s][v] + len < d[s][to]) {
                    d[s][to] = d[s][v] + len;
                    q.push (make_pair (-d[s][to], to));
                }
            }
        }
    }
//    for (int k=0; k<n; ++k)
//        for (int i=0; i<n; ++i){
//
//            for (int j=0; j<n; ++j) {
//                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
//            }
//        }
//    forn()
//    for (int k=0; k<n; ++k)
//        for (int i=0; i<n; ++i)
//            for (int j=0; j<n; ++j){
//                if(d[i][k] + d[k][j] < d[i][j]) {
//                    d[i][j] = d[i][k] + d[k][j];
//                    p[i][j] = k;
//                }
//            }
    vpi sk;
    forn(i,0,k) {
        vi res;
        int a,b;
        cin>>a>>b;
//        if()
        a--; b--;
        sk.pb(mp(a,b));
        cur+=d[a][b];
    }
//        cur+=d[a][b];
//        res.pb(a);
//        for(auto x : get(a,b)) res.pb(x);
//        res.pb(b);
//
//        forn(i,0,res.size()-1) {
//            int u = res[i];
//            int v = res[i+1];
//            if(u>v) swap(u,v);
//            cnt[mp(u,v)] += 1;
//        }
//    }
    ll ans = cur;
    
    forn(del,0,m) {
        int u = e[del].first;
        int v = e[del].second;
        cur = 0;
        forn(i,0,k) {
            int a = sk[i].first;
            int b=  sk[i].second;
            cur += min(min(d[a][u] + d[b][v], d[a][v] + d[b][u]), d[a][b]);
        }
        ans = min(ans,cur);
    }
    cout<<ans;
}