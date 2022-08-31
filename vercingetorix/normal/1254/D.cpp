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

const long long mod = 998244353;
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
int n;
vvi g;
vi par;
vvi ch;
vi hc;
vi hpar;
vi st;
int curt = 0;
vi tin,tout;

void dfs(int v, int p) {
    tin[v] = curt++;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u==p) continue;
        par[u] = v;
        ch[v].pb(u);
        dfs(u, v);
        st[v] += st[u];
    }
    tout[v] = curt-1;
}

void dfs2(int v, int p) {
    for(auto u : g[v]) {
        if(u==p) continue;
        hpar[u] = hpar[hpar[u]];
        dfs2(u, v);
    }
}

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
class stree {
public:
    vll t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = (t[v] + val) % mod;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
        }
    }
    
    ll get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d %d", &n ,&q);
    ll ni = invmod(n, mod);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    par.resize(n);
    ch.resize(n);
    hc = vi(n,-1);
    hpar = vi(n,-1);
    tin.resize(n);
    tout.resize(n);
    st.resize(n);
    forn(i,0,n) hpar[i] = i;
    dfs(0,0);
    forn(v,0,n) {
        for(auto u : ch[v]) if(st[u]*2>=st[v]) {
            hc[v] = u;
            hpar[u] = v;
        }
    }
    dfs2(0,0);
    stree sta;
    sta.build(n, 1, 0, n-1);
    vll ver(n, 0);
    while(q--) {
        int tp, v;
        scanf("%d %d", &tp, &v);
        v--;
        if(tp == 1) {
            int d;
            scanf("%d", &d);
            ll val = ni*st[v]%mod*d%mod;
            sta.update(1, 0, n-1, 0, n-1, val);
            sta.update(1, 0, n-1, tin[v], tout[v], mod-val);
            if(hc[v] != -1) {
                int u = hc[v];
                val = ni*(n-st[u])%mod*d%mod;
                sta.update(1, 0, n-1, tin[u], tout[u], val);
            }
            ver[v] = (ver[v] + d)%mod;
        }
        else {
            ll res = sta.get(1, 0, n-1, tin[v]) + ver[v];
            v = hpar[v];
            while(v != 0) {
                int p = par[v];
                res = (res + ver[p]*(n-st[v])%mod*ni)%mod;
                v = hpar[p];
            }
            printf("%lld\n", res%mod);
        }
    }
    
    
    
    
}