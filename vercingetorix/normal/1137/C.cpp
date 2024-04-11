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
int n,m,w;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}
vvi comp;
int cc = 0;
vi cnum;
vi vis;
vi gcomp;
int curg;
vi lev;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int d[50][100500];

void dfscomp(int u, int l) {
    vis[u] = 1;
    lev[u] = l;
    for(auto v : g[u]) {
        if(cnum[v] == cnum[u]) {
            if(vis[v]) {
                curg = gcd(curg, lev[u] - lev[v] + 1);
            }
            else dfscomp(v, l+1);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d %d", &n, &m, &w);
    g.resize(n);
    gr.resize(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        gr[v].pb(u);
    }
    vs a;
    char c[200];
    forn(i,0,n) {
        scanf("\n%s", c);
        a.pb(string(c));
    }
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    cnum = vi(n,0);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            comp.pb(component);
            for(auto x : component) cnum[x] = cc;
            cc++;
            component.clear();
        }
    }
    vis = vi(n, 0);
    lev = vi(n, 0);
    forn(c,0,cc) {
        curg = w;
        dfscomp(comp[c][0], 0);
        gcomp.pb(curg);
        for(auto u : comp[c]) lev[u] %= curg;
    }
    for(int ci = cc-1; ci>=0; ci--) {
        int p = gcomp[ci];
        forn(e,0,p) {
            int bout = 0;
            int bin = 0;
            for(auto u : comp[ci]) {
                int s = (e+lev[u])%p;
                for(int j = s; j<w; j+=p) {
                    if(a[u][j] == '1') {
                        bin++;
                        break;
                    }
                }
                for(int j = (s+1)%p; j < w; j+=p) for(auto v : g[u]) if(cnum[v] != cnum[u]) bout = max(bout, d[j][v]);
            }
            for(auto u : comp[ci]) {
                int s = (e+lev[u])%p;
                for(int j = s; j < w; j+=p) d[j][u] = bin+bout;
            }
        }
    }
//    forn(j,0,n) {
//        forn(i,0,w) cout<<d[i][j];
//        cout<<endl;
//    }
    int ans = 0;
//    forn(i,0,w) ans = max(ans, d[i][0]);
    cout<<d[0][0];
}