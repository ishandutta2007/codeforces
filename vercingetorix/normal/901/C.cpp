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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vvpi nb;
vpi par;
vi lvl;
vi vis;
vi t;

void dfs(int v, int p) {
    vis[v] = 1;
    for(auto u : nb[v]) {
        if(vis[u.first] == 0) {
            lvl[u.first] = lvl[v] + 1;
            par[u.first] = mp(v, u.second);
            t[u.second] = 1;
            dfs(u.first, v);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    nb.resize(n);
    lvl.resize(n);
    par.resize(n);
    vis = vi(n,0);
    t = vi(m,0);
    vpi e;
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        nb[u].pb(mp(v, i));
        nb[v].pb(mp(u, i));
        e.pb(mp(u,v));
    }
    forn(i,0,n) if(!vis[i]) {
        lvl[i] = 0;
        dfs(i,0);
    }
    vi ban(n, -1);
    forn(i,0,m) if(t[i] == 0) {
//        int mni = i;
//        int mxi = i;
        int u = e[i].first;
        int v = e[i].second;
        int mni = min(u, v);
        int mxi = max(u,v);
        while(lvl[u] > lvl[v]) {
            int ind = par[u].first;
            u = par[u].first;
            mni = min(mni, ind);
            mxi = max(mxi, ind);
        }
        while(lvl[v] > lvl[u]) {
            int ind = par[v].first;
            v = par[v].first;
            mni = min(mni, ind);
            mxi = max(mxi, ind);
        }
        while(u!=v) {
            int ind = par[v].first;
            v = par[v].first;
            mni = min(mni, ind);
            mxi = max(mxi, ind);
            ind = par[u].first;
            u = par[u].first;
            mni = min(mni, ind);
            mxi = max(mxi, ind);
        }
        ban[mxi] = max(ban[mxi], mni);
    }
    ll l1 = 0;
    vll len;
    vll cumlen(1,0);
    forn(r, 0, n) {
        l1 = max(l1, ll(ban[r] + 1));
        ban[r] = l1;
        len.pb(r-l1+1);
        cumlen.pb(cumlen.back() + len.back());
    }
    int q;
    scanf("%d", &q);
    forn(fafa,0,q) {
        int a,b;
        scanf("%d %d", &a, &b);
        b--; a--;
        int l = a;
        int r = b+1;
        while(r-l > 1) {
            int m = (l+r)/2;
            if(ban[m] <= a) l = m;
            else r = m;
        }
        ll ans = cumlen[b+1] - cumlen[l+1];
        ll num = l-a +1;
        ans += num*(num+1)/2;
        printf("%lld\n", ans);
        
    }
    
    
}