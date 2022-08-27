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

const long long mod = 1000000007;
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
ll gcd (ll a, ll b, ll & x, ll & y) {
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

const int A = 200500;
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
const int N = 200500;
int mindiv[N+1];
vector<ll> pr;
int isp[N+1];
int sq[N+1];
ll caf[N+1];
int l;
int lev[N];
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
vvi g;

void dfs1 (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            lev[to] = lev[v] + 1;
            dfs1 (to, v);
        }
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dist(int a, int b) {
    return lev[a] + lev[b] - 2*lev[lca(a,b)];
}

const int C = 450;
vi smallsq;
ll phi[N+1];
ll sphi[N+1];
ll sdphi[N+1];
int ban[A];
int st[A];
int a[A];
ll ans = 0;

int dfsst(int v, int p) {
    st[v] = 1;
    for(auto u : g[v]) {
        if(u == p || ban[u]) continue;
        st[v] += dfsst(u, v);
    }
    return st[v];
}

int dfsroot(int v, int p, int compsize) {
    for(auto u : g[v]) {
        if(ban[u] || u == p) continue;
        if(st[u]*2>=compsize) return dfsroot(u, v, compsize);
    }
    return v;
}

int curdist = 0;

void dfs(int v, int p) {
    curdist++;
    for(auto x  : smallsq) if(a[v]%x == 0) {
        sphi[x] = (phi[a[v]]+sphi[x])%mod;
        sdphi[x] = (phi[a[v]]*curdist+sdphi[x])%mod;
    }
    for(auto u : g[v]) {
        if(u == p || ban[u]) continue;
        dfs(u, v);
    }
    curdist--;
}

void solve(int v) {
    dfsst(v, v);
    v = dfsroot(v, v, st[v]);
    vll sumphi(smallsq.size(), 0);
    vll sumdphi(smallsq.size(), 0);
    for(auto u : g[v]) if(!ban[u]) {
        dfs(u,v);
        forn(i,0,smallsq.size()) {
            ans = (ans + (sumphi[i]*sdphi[smallsq[i]]+sumdphi[i]*sphi[smallsq[i]])%mod*caf[smallsq[i]])%mod;
            sumphi[i] += sphi[smallsq[i]];
            sphi[smallsq[i]] = 0;
            sumdphi[i] += sdphi[smallsq[i]];
            sdphi[smallsq[i]] = 0;
        }
    }
    forn(i,0,smallsq.size()) {
//        ll sumdphi = 0;
//        forn(j,0,asp.size()) sumdphi += asdp[j][i];
//        sumdphi %= mod;
//        forn(j,0,asp.size()) {
//            ans = (ans + asp[j][i]*(sumdphi +mod- asdp[j][i])%mod*caf[smallsq[i]])%mod;
//        }
        if(a[v]%smallsq[i] == 0) ans = (ans + sumdphi[i]*phi[a[v]]%mod*caf[smallsq[i]])%mod;
    }
    ban[v] = 1;
    for(auto u : g[v]) if(!ban[u]) solve(u);
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    sq[1] = 1;
    caf[1] = 1;
    phi[1] = 1;
    forn(i,2,N+1) {
        if(i/mindiv[i]%mindiv[i]==0) phi[i] = phi[i/mindiv[i]]*mindiv[i];
        else phi[i] = phi[i/mindiv[i]]*(mindiv[i]-1);
        if(sq[i/mindiv[i]] && i/mindiv[i]%mindiv[i]!=0) {
            sq[i] = 1;
            caf[i] = caf[i/mindiv[i]]*mindiv[i]%mod*in[mindiv[i]-1]%mod;
        }
    }
    forn(i,1,C) if(sq[i]) smallsq.pb(i);
    
    for(auto p : pr) {
        for(int i = p; i<=N; i+=p) if(sq[i]) {
            caf[i] = (caf[i]+mod-caf[i/p])%mod;
        }
    }
//    caf[2] = 0;
//    caf[3] = 0;
//    caf[5]= 0;
//    caf[2] = 2;
    int n;
    scanf("%d", &n);
    while(smallsq.back() > n) smallsq.pop_back();
    forn(i,0,n) scanf("%d", &a[i]);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi w(n+1);
    forn(i,0,n) w[a[i]] = i;
    
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0, 0);
    solve(0);
    forn(div,C,n+1) if(sq[div]) {
        for(int u = div; u<= n ; u+=div) for(int v = u+div; v<=n; v+=div) {
            ans = (ans + phi[u]*phi[v]%mod*dist(w[u], w[v])%mod*caf[div])%mod;
        }
    }
//    cout<<ans<<'\n';
//    ans = 0;
//    forn(u,0,n) forn(v,u+1,n) ans = ans + phi[a[u]]*phi[a[v]]*dist(u,v);
    ans=ans*2*in[n]%mod*in[n-1]%mod;
    cout<<ans<<'\n';
    
}