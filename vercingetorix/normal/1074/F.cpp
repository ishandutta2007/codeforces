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

// min + col
// add
pi combine(pi a, pi b) {
    if(a.first < b.first) return a;
    else if(b.first < a.first) return b;
    else return mp(a.first, a.second + b.second);
}
const int INF = 1e9;
class stree {
public:
    vpi t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = mp(0,1);
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v].first += pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
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
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return mp(INF, 0);
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        pi ret =  combine(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = combine(t[v*2], t[v*2+1]);
        return ret;
    }
};

int l;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
vvi g;
int vis = 0;
vi sl,sr;
void dfs1 (int v, int p = 0) {
    sl[v] = vis++;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs1 (to, v);
    }
    tout[v] = ++timer;
    sr[v] = vis-1;
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

int pred(int a, int c) {
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], c))
            a = up[a][i];
    return a;
}

stree st;
int n,m;


void go(int a, int b, int w) {
    int c = lca(a,b);
    if(c == b) swap(a,b);
    if(c == a) {
        a = pred(b,c);
        st.update(1, 0, n-1, sl[a], sr[a], w);
        st.update(1, 0, n-1, sl[b], sr[b], -w);
    }
    else {
        st.update(1, 0, n-1, 0, n-1, w);
        st.update(1, 0, n-1, sl[a], sr[a], -w);
        st.update(1, 0, n-1, sl[b], sr[b], -w);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    g.resize(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    sl.resize(n);
    sr.resize(n);
    dfs1 (0, 0);
    
    st.build(n, 1, 0, n-1);
    set<pi> in;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(u>v) swap(u,v);
        auto it = in.find(mp(u,v));
        if(it == in.end()) {
            in.insert(mp(u,v));
            go(u,v,1);
        }
        else {
            in.erase(it);
            go(u,v,-1);
        }
        auto res = st.get(1, 0, n-1, 0, n-1);
        if(res.first != 0) res.second = 0;
        printf("%d\n", res.second);
    }
}