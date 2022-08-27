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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

class stree {
public:
    vll t;
    void build (int n, int v, int tl, int tr) {
        t = vll(4*n, 0);
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = (add + t[v])%mod;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
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

vvi ch;
vi par;
vi trav;
vi pos, rpos;
vi lvl;
void bfs(int v) {
    pos[v] = trav.size();
    trav.pb(v);
    for(auto u : ch[v]) {
        lvl[u] = lvl[v] + 1;
        bfs(u);
    }
    rpos[v] = trav.size()-1;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    par.resize(n);
    ch.resize(n);
    par[0] = 0;
    forn(i,1,n) {
        scanf("%d", &par[i]);
        par[i]--;
        ch[par[i]].pb(i);
    }
    pos.resize(n);
    lvl.resize(n);
    rpos.resize(n);
    lvl[0] = 0;
    bfs(0);
    stree stl;
    stree st;
    st.build(n, 1, 0, n-1);
    stl.build(n, 1, 0, n-1);
    int q;
    scanf("%d", &q);
    forn(i,0,q) {
        int t,v;
        scanf("%d %d", &t, &v);
        v--;
        if(t == 1) {
            int x,k;
            scanf("%d %d", &x, &k);
            stl.update(1, 0, n-1, pos[v], rpos[v], mod-k);
            st.update(1, 0, n-1, pos[v], rpos[v], (x + ll(k)*lvl[v])%mod);
        }
        else {
            ll ans = st.get(1, 0, n-1, pos[v]);
            ll add = stl.get(1, 0, n-1, pos[v])%mod;
            ans = (ans + add*lvl[v])%mod;
            printf("%lld\n", ans);
        }
    }
    
}