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

const long long mod = 998244353 ;
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
vvi g;
vvi a;
vll imod(1000);
vll ifac(1000);
vll fac(1000);
vi vis;
vvi comp;
vvi compv;
vvi touched;

void dfs(int v) {
    vis[v] = 1;
    comp.back().pb(v);
    for(auto u : g[v]) {
        if(!vis[u]) dfs(u);
    }
}
vi hp;
vi ts;
int curpart = 1;
vvi b;
vvi kaka;
int n,m;
void split(int u, int v) {
    kaka= vvi(3);
    forn(i,0,n) {
        if(a[u][i] == 1) {
            if(a[v][i] == 0) kaka[0].pb(i);
            else kaka[1].pb(i);
        }
        else if(a[v][i] == 1) kaka[2].pb(i);
    }
}
int can;

void addkaka(int v) {
    vi ina(n,0);
    forn(i,0,n) if(a[v][i]) ina[i] = 1;
    int l = kaka.size();
    vvi ka1(l), ka2(l);
    vi per;
    forn(i,0,kaka.size()) {
        for(auto x : kaka[i]) {
            ina[x] = 0;
            if(a[v][x]) ka1[i].pb(x);
            else ka2[i].pb(x);
        }
        if(ka1[i].size() > 0) per.pb(i);
    }
    int y = per.size();
    forn(i,0,y-1) if(per[i]+1 != per[i+1]) {
        can = 0;
        return;
    }
    forn(i,1,y-1) if(ka2[per[i]].size() > 0) {
        can = 0;
        return;
    }
    vi xtra;
    forn(i,0,n) {
        if(ina[i]) xtra.pb(i);
    }
    if(xtra.size() > 0) {
        if(per[0] == 0 && (per.size() == 1 || ka2[0].size() == 0)) {
//            if(per.size() > 1 && ka2[0].size() > 0) {
//                can = 0;
//                return;
//            }
            kaka.clear();
            kaka.pb(xtra);
            forn(i,0,l) {
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
            }
        }
        else if(per.back() == l-1 && (per.size() == 1 || ka2[l-1].size() == 0)) {
//            if(per.size() > 1 && ka2[l-1].size() > 0) {
//                can = 0;
//                return;
//            }
            kaka.clear();
            forn(i,0,l) {
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
            }
            kaka.pb(xtra);
        }
        else {
            can = 0;
            return;
        }
    }
    else {
        kaka.clear();
        forn(i,0,l) {
            if(i<=per[0]) {
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
            }
            else {
                if(ka1[i].size() > 0) kaka.pb(ka1[i]);
                if(ka2[i].size() > 0) kaka.pb(ka2[i]);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll curfac = 1;
    forn(i,1,200) {
        imod[i] = invmod(i, mod);
        curfac = curfac*i%mod;
        fac[i] = curfac;
        ifac[i] = invmod(curfac, mod);
    }
    
    scanf("%d %d", &n, &m);
    a = vvi (m, vi(n,0));
    ll ans = fac[n];
    b.resize(m);
    forn(i,0,m) {
        int q;
        scanf("%d", &q);
        forn(j,0,q) {
            int x;
            scanf("%d", &x);
            x--;
            b[i].pb(x);
            a[i][x] = 1;
        }
    }
    vi ao;
    g.resize(m);
    forn(i,0,m) forn(j,i+1,m) {
        int can1 = 0, can2 = 0, can3 = 0;
        forn(k,0,n) {
            if(a[i][k] > a[j][k]) can1 = 1;
            if(a[i][k] < a[j][k]) can2 = 1;
            if(a[i][k] * a[j][k] == 1) can3 = 1;
        }
        if(can1 + can2 + can3 == 3) {
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    vis = vi(m, 0);
    forn(i,0,m) if(!vis[i]) {
        comp.pb(vi());
        dfs(i);
    }
    int k = comp.size();
    compv.resize(k);
//    vpi cord;
    vector<pair<pi, int>> cord;
    forn(i,0,k) {
        vi tk(n,0);
        for(auto x : comp[i]) {
            forn(j,0,n) tk[j] |= a[x][j];
        }
        int sum = 0;
        for(auto x : tk) sum+=x;
        cord.pb(mp(mp(sum, -(int)comp[i].size()), i));
        forn(j,0,n) {
            if(tk[j]) compv[i].pb(j);
        }
    }
    srtrev(cord);
    hp = vi(n,0);
    ts = vi(1005000, 0);
    ts[0] = n;
    for(auto cc : cord) {
        int ind = cc.second;
        int prt = hp[compv[ind][0]];
        int clen = cc.first.first;
        forn(i,1,clen) if(hp[compv[ind][i]] != prt) {
            ans = 0;
            break;
        }
        ans = ans * ifac[ts[prt]] % mod;
        ts[prt] -= clen-1;
        ans = ans * fac[ts[prt]] % mod;
        if(ans == 0) break;
        if(comp[ind].size() == 1) {
            for(auto x : compv[ind]) hp[x] = curpart;
            ts[curpart] = (int)compv[ind].size();
            ans = ans*fac[ts[curpart]] %mod;
            curpart++;
            continue;
        }
        ans = ans*2%mod;
        can = 1;
        split(comp[ind][0], comp[ind][1]);
        forn(i,2,comp[ind].size()) {
            addkaka(comp[ind][i]);
            if(can == 0) break;
        }
        if(can == 0) {
            ans = 0;
            break;
        }
        for(auto x : kaka) {
            ans = ans*fac[x.size()] % mod;
            for(auto y : x) hp[y] = curpart;
            ts[curpart] = x.size();
            curpart++;
        }
        
    }
    cout<<ans;
    
    
    
}