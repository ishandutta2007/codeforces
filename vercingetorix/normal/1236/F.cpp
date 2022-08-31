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
#ifdef LOCAL
const int A = 20;
#else
const int A = 500500;
#endif
vi g[A];

int vis[A];
int par[A];
int lev[A];
vvi cyc;

void dfs(int v, int p) {
    vis[v] = 1;
    for(auto u : g[v]) {
        if(u == p) continue;
        if(vis[u]) {
            if(lev[u] < lev[v]) {
                cyc.pb(vi(1,u));
                int cur = v;
                while(cur != u) {
                    cyc.back().pb(cur);
                    cur = par[cur];
                }
            }
        }
        else {
            par[u] = v;
            lev[u] = lev[v]+1;
            dfs(u, v);
        }
    }
}
vi cp[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vll di2(1,1);
    ll i2 = (mod+1)/2;
    forn(i,0,2*A) di2.pb(di2.back()*i2%mod);
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(0,0);
    ll v = n*i2%mod;
    ll e = m*di2[2]%mod;
    ll c = 0;
    for(auto x : cyc) c += di2[x.size()];
    for(auto y : cyc) for(auto x : y) cp[x].pb(y.size());
    c%=mod;
    ll v2 = (v*v + n * (di2[1] + mod - di2[2]))%mod;
    ll e2 = (e*e + m * (di2[2] + mod - di2[4])) % mod;
    forn(i,0,n) {
        ll num = g[i].size();
        e2 += num*(num-1) % mod * (di2[3] + mod - di2[4]) % mod;
    }
    ll c2 = c*c%mod;
    for(auto x : cyc) c2 = mod + c2 + di2[x.size()] - di2[x.size()*2];
    c2 %= mod;
    forn(v,0,n) if(cp[v].size() > 1) {
        ll cs = 0;
        ll cs2 = 0;
        for(auto x : cp[v]) cs += di2[x];
        for(auto x : cp[v]) cs2 += di2[2*x];
        cs %= mod;
        cs2 %= mod;
        cs = (cs * cs + mod - cs2)%mod;
        c2 = (c2 + cs)%mod;
    }
    ll ve = v*e%mod;
    ve = (ve+e)%mod;
    ll vc = v*c%mod;
    for(auto x : cyc) {
        vc = (vc + x.size()*di2[x.size()+1])%mod;
    }
    ll ec = e*c%mod;
    for(auto x : cyc) {
        ec = (ec + x.size()*3*di2[x.size()+2])%mod;
        int out = 0;
        for(auto y : x) out += g[y].size()-2;
        ec = (ec + out*di2[x.size()+2])%mod;
    }
    ll EV = (v+mod-e+c)%mod;
    ll EV2 = (4*mod+v2+e2+c2-2*ve-2*ec+2*vc)%mod;
    ll ans = (EV2-EV*EV%mod+mod)%mod;
    cout<<ans;
    
}