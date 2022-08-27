#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

class stree {
public:
    vpll t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = mp(0, 1);
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v].first = t[v*2].first + t[v*2+1].first;
            t[v].second = (t[v*2].second * t[v*2+1].second)%mod;
        }
    }
    
    void set (int v, int tl, int tr, int pos, pll to) {
        if (pos == tl && tr == pos) {
            t[v].first += to.first;
            t[v].second = (to.second * t[v].second) % mod;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, to);
            else set(v*2+1, tm+1, tr, pos, to);
            t[v].first = t[v*2].first + t[v*2+1].first;
            t[v].second = (t[v*2].second * t[v*2+1].second)%mod;
        }
    }
    
    pll get (int v, int tl, int tr, int l, int r) {
        if(l>r) return mp(0,1);
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        pll t1 = get (v*2, tl, tm, l, min(r,tm));
        pll t2 = get(v*2+1, tm+1, tr, max(l,tm+1), r);
        return mp(t1.first + t2.first, (t1.second*t2.second)%mod);
    }
};
int n;

vll x, xinv; vi c, ban, s;
vvpi nb;
vvpi ch;
int root;

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
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}

void dfs(int v, int p, int sz) {
    s[v] = 1;
    ch[v].clear();
    for(auto u : nb[v]) {
        if(ban[u.first] || u.first == p) continue;
        ch[v].pb(u);
        dfs(u.first, v, sz);
        s[v] += s[u.first];
    }
    if (2*s[v] >= sz && root == -1) root = v;
}
vector<vector<pair<pi, ll> >> e;
int cnt[2]; ll cur;

void dfse(int v, vector<pair<pi, ll>> & to) {
    to.pb(mp(mp(cnt[0],cnt[1]), cur));
    for(auto u : ch[v]) {
        cur = (cur * x[u.second]) % mod;
        cnt[c[u.second]]++;
        dfse(u.first, to);
        cur = (cur * xinv[u.second]) % mod;
        cnt[c[u.second]]--;
    }
}
stree vu2, uv2;
ll powM(ll k, ll n, ll modulo) {
    if (n==0) return 1;
    if(n==1) return k;
    ll x = powM(k, n/2, modulo);
    return (((x*x)%modulo)*powM(k, n%2, modulo)) % modulo;
}
ll ans = 1;
void proc(int v) {
    dfs(v, -1, 0);
    root = -1;
    dfs(v, -1, s[v]);
    dfs(root, -1, 0);
    pll total = mp(0, 1);
    for (auto u : ch[root]) {
        e[u.first].clear();
        cur = x[u.second]; cnt[0] = 0; cnt[1] = 0; cnt[c[u.second]]++;
        dfse(u.first, e[u.first]);
        for(auto ex : e[u.first]) {
            int p = ex.first.first;
            int q = ex.first.second;
            ll val = ex.second;
            pll bad1 = uv2.get(1, 0, 3*n, 2*q-p+1+2*n, 3*n);
            pll bad2 = vu2.get(1, 0, 3*n, 2*p-q+1+2*n, 3*n);
            ans = (ans * powM(val, total.first - bad1.first - bad2.first, mod)) % mod;
            ans = (ans * total.second) % mod;
            ans = (ans * invmod(bad1.second, mod)) % mod;
            ans = (ans * invmod(bad2.second, mod)) % mod;
        }
        for(auto ex : e[u.first]) {
            int p = ex.first.first;
            int q = ex.first.second;
            ll val = ex.second;
            total.first ++;
            total.second = (total.second * val) % mod;
            uv2.set(1, 0, 3*n, p-2*q+2*n, mp(1, val));
            vu2.set(1, 0, 3*n, q-2*p+2*n, mp(1, val));
        }
    }
    pll bad1 = uv2.get(1, 0, 3*n, 1+2*n, 3*n);
    pll bad2 = vu2.get(1, 0, 3*n, 1+2*n, 3*n);
    ans = (ans * total.second) % mod;
    ans = (ans * invmod(bad1.second, mod)) % mod;
    ans = (ans * invmod(bad2.second, mod)) % mod;
    for (auto u : ch[root]) {
        for(auto ex : e[u.first]) {
            int p = ex.first.first;
            int q = ex.first.second;
            ll val = ex.second;
            ll ival = invmod(val, mod);
            uv2.set(1, 0, 3*n, p-2*q+2*n, mp(-1, ival));
            vu2.set(1, 0, 3*n, q-2*p+2*n, mp(-1, ival));
        }
    }
    
    ban[root] = 1;
    for (auto u : nb[root]) if(!ban[u.first]) proc(u.first);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    vu2.build(3*n+1, 1, 0, 3*n);
    uv2.build(3*n+1, 1, 0, 3*n);
    x.resize(n); c.resize(n); ban.resize(n); nb.resize(n); e.resize(n); s.resize(n); ch.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d %lld %d", &u, &v, &x[i], &c[i]);
        u--; v--;
        nb[v].pb(mp(u,i)); nb[u].pb(mp(v,i));
    }
    for(auto u : x) xinv.pb(invmod(u, mod));
    proc(0);
    cout<<ans;
}