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
const int A = 100500;
#endif
int tl[A];
int tr[A];
int lev[A];
int timer2 = 0;
int n;
int l;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
vvi g;

void dfs1 (int v, int p = 0) {
    tl[v] = timer2++;
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
    tr[v] = timer2-1;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int golev(int a, int to) {
    for (int i=l; i>=0; --i)
        if(lev[a] - (1<<i) >= to)
            a = up[a][i];
    return a;
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
int ans[A];

vector<pair<int, pi>> ev[A];

class stree {
public:
    vi t;
    vi pp;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            int n = a.size();
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v] += pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v, tl, tr);
        //        }
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = max(t[v*2], t[v*2+1]);
        return ret;
    }
};

stree st;

void dfslast(int v, int p) {
    for(auto x : ev[v]) {
        ans[x.first] = max(ans[x.first], st.get(1, 0, n-1, x.second.first, x.second.second));
    }
    for(auto u : g[v]) {
        if(u==p) continue;
        st.update(1, 0, n-1, 0, n-1, 1);
        st.update(1, 0, n-1, tl[u], tr[u], -2);
        dfslast(u, v);
        st.update(1, 0, n-1, 0, n-1, -1);
        st.update(1, 0, n-1, tl[u], tr[u], 2);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d", &n);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs1 (0,0);
    
    int m;
    scanf("%d", &m);
    forn(i,0,m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        int c = lca(u,v);
        int d = lev[u] + lev[v] - 2*lev[c];
        if(lev[v] - lev[c] < lev[u] - lev[c]) swap(u,v);
        int v1 = golev(v, lev[v] - (d-1)/2);
        ev[v].pb(mp(i, mp(tl[v1], tr[v1])));
        ev[u].pb(mp(i, mp(0, tl[v1]-1)));
        ev[u].pb(mp(i, mp(tr[v1]+1, n-1)));
    }
    vi b(n);
    forn(i,0,n) b[tl[i]] = lev[i];
//    forn(i,0,n) b.pb(lev[i]);
    st.build(b, 1, 0, n-1);
    dfslast(0, 0);
    forn(i,0,m) printf("%d\n", ans[i]);
    
    
}