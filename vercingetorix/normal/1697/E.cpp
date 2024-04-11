#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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

const long long mod = 998244353 ;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
const int A = 102;
int d[A][A];

int n;
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

vvi comps;
void scc() {
    order.clear();
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            // new component
            comps.pb(component);
            component.clear();
//            return;
        }
    }
}ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

ll nfac[A];
ll ifac[A];
ll in[A];

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

ll cnk(int n, int k) {
    if(k<0 || k>n) return 0;
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    cin>>n;
    vi x(n), y(n);
    forn(i,0,n) cin>>x[i]>>y[i];
    forn(i,0,n) forn(j,0,n) d[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
    g.resize(n);
    gr.resize(n);
    vi dmn;
    forn(i,0,n) {
        int mn = 1e9;
        forn(j,0,n) if(i!=j) mn = min(mn, d[i][j]);
        dmn.pb(mn);
        forn(j,0,n) if(d[i][j] == mn) {
            g[i].pb(j);
            gr[j].pb(i);
        }
    }
    scc();
    vi cnum(n,0);
    forn(i,0,comps.size()) for(auto j : comps[i]) cnum[j] = i;
    
//    for(auto x : comps) {
//        for(auto y : x) cout<<y<<' '; cout<<'\n';
//    }
    vll p(n+1,0);
    p[0] = 1;
    for(auto x : comps) {
        int bad = 0;
        for(auto y : x) for(auto z : g[y]) if(cnum[z] != cnum[y]) bad = 1;
        for(auto y : x) if(dmn[y] != dmn[x[0]]) bad = 1;
        for(auto y : x) for(auto z : x) if(z!=y && d[y][z] != dmn[y]) bad = 1;
        vll np(n+1,0);
        forn(was,0,n+1) {
            if(was + x.size() <= n) np[was+x.size()] = (np[was+x.size()] + p[was])%mod;
            if(x.size() > 1 &&  bad == 0 && was<n) np[was+1] = (np[was+1] + p[was])%mod;
        }
        p = np;
    }
    
    ll ans = 0;
    forn(pt,1,n+1) {
        ans = (ans + p[pt]*cnk(n, pt)%mod*nfac[pt])%mod;
    }
    cout<<ans;
    
}