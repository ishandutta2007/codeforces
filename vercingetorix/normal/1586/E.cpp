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
int n,m;
vvi gor;
vector<set<pi>> g;
vi path;
vi vis;
void dfsp(int v, int to) {
    vis[v] = 1;
    if(v == to) {
        path.pb(to);
        return;
    }
    for(auto u : gor[v]) {
        if(vis[u] == 0) {
            dfsp(u, to);
            if(!path.empty()) {
                path.pb(v);
                return;
            }
        }
    }
}

void getpath(int u, int v) {
    vis = vi(n,0);
    path.clear();
    dfsp(v, u);
}

vi p1, p2;
vi fin;

void dfsf(int v) {
    vis[v] = 1;
    if(fin[v] == 1) {
        path.pb(v);
        return;
    }
    for(auto u : gor[v]) {
        if(vis[u] == 0) {
            dfsf(u);
            if(!path.empty()) {
                path.pb(v);
                return;
            }
        }
    }
}

void gettopath(int v, vi p) {
    vis = vi(n,0);
    fin = vi(n,0);
    for(auto x : p) fin[x] = 1;
    path.clear();
    dfsf(v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    g.resize(n);
    gor.resize(n);
    vpi e;
    vi deg(n,0);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        gor[u].pb(v);
        gor[v].pb(u);

    }
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        deg[u]^=1;
        deg[v]^=1;
        g[u].insert(mp(v,i));
        g[v].insert(mp(u,i));
        e.pb(mp(u,v));
    }
    int cbad = 0;
    forn(i,0,n) cbad += deg[i];
    if(cbad > 0) {
        printf("NO\n");
        printf("%d\n", cbad/2);
        exit(0);
    }
    vpi rf;
    vi rto;
    vi vrec;
    int qcnt = q;
    vvi ans(2*q);
    forn(i,0,n) {
        while(g[i].size() > 0) {
            auto x1 = *g[i].begin();
            g[i].erase(g[i].begin());
            g[x1.first].erase(mp(i, x1.second));
            auto x2 = *g[i].begin();
            g[i].erase(g[i].begin());
            g[x2.first].erase(mp(i, x2.second));
            if(x1.first == x2.first) {
                getpath(i, x1.first);
                ans[x1.second] = path;
                ans[x2.second] = path;
            }
            else {
                e.pb(mp(x1.first, x2.first));
                rf.pb(mp(x1.second, x2.second));
                g[x1.first].insert(mp(x2.first, qcnt));
                g[x2.first].insert(mp(x1.first, qcnt));
                rto.pb(qcnt++);
                vrec.pb(i);
            }
        }
    }
    while(!rto.empty()) {
        int v = vrec.back();
        vrec.pop_back();
        gettopath(v, ans[rto.back()]);
        
//        reverse(all(path));
        int ind = rf.back().first;
        int u = e[ind].first + e[ind].second - v;
        if(ans[rto.back()][0] != u) reverse(all(ans[rto.back()]));
        for(auto x : ans[rto.back()]) {
            if(x == path[0]) break;
            else ans[ind].pb(x);
        }
        for(auto x : path) ans[ind].pb(x);
        
        ind = rf.back().second;
        u = e[ind].first + e[ind].second - v;
        if(ans[rto.back()][0] != u) reverse(all(ans[rto.back()]));
        for(auto x : ans[rto.back()]) {
            if(x == path[0]) break;
            else ans[ind].pb(x);
        }
        for(auto x : path) ans[ind].pb(x);
        rf.pop_back();
        rto.pop_back();
    }
    printf("YES\n");
    forn(i,0,q) {
        if(ans[i][0] != e[i].first) reverse(all(ans[i]));
        printf("%d\n", ans[i].size());
        for(auto x : ans[i]) printf("%d ", x+1);
        printf("\n");
        
    }
    
    
    
}