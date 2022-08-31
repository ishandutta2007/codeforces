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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
vll cg;
vi vis;
vvpi gm;
vll d;
int n, m;
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

vi cn;
int compnum = 0;

void dfs(int v, int p, ll curd) {
    vis[v] = 1;
    d[v] = curd;
    for(auto u : gm[v]) {
        if (cn[u.first] != cn[v]) continue;
        if(vis[u.first]) {
            ll cl = d[v] - d[u.first] + u.second;
            cg[cn[v]] = gcd(cg[cn[v]], cl);
        }
        else dfs(u.first, v, curd + u.second);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    g.resize(n);
    gr.resize(n);
    gm.resize(n);
    d = vll(n,0);
    forn(i,0,m) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        u--; v--;
        gm[u].pb(mp(v, l));
        g[u].pb(v);
        gr[v].pb(u);
    }
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    cn.resize(n);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            for(auto v : component) cn[v] = compnum;
            compnum ++;
            component.clear();
        }
    }
    cg = vll(compnum, 0);
    vis = vi(n, 0);
    forn(i,0,n) if(vis[i] == 0) dfs(i,i,0);
    int q;
    scanf("%d", &q);
    while(q--) {
        int v,s,t;
        scanf("%d %d %d", &v, &s, &t);
        v--;
        ll uf = cg[cn[v]];
        if(s == 0) {
            printf("YES\n");
            continue;
        }
        if(uf == 0) {
            printf("NO\n");
            continue;
        }
        ll can = gcd(t, uf);
//        ll need = gcd(s,t);
        if(s%can == 0) {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    
    
    
}