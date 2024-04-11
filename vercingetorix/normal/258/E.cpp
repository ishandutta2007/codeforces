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
const int A = 100500;
vi g[A];
int pl[A];
int pr[A];
int timer;
void dfs1(int v, int p) {
    pl[v] = timer++;
    for(auto u : g[v]) if(u!=p) dfs1(u, v);
    pr[v] = timer-1;
}

vi to[A];
pi operator+(const pi & a, const pi & b) {
    if(a.first == b.first) return mp(a.first, a.second + b.second);
    else if(a<b) return a;
    else return b;
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
            t[v] = t[v*2] + t[v*2+1];
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
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return mp(INF,0);
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        pi ret =  get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
        t[v] = (t[v*2] + t[v*2+1]);
        return ret;
    }

};
stree st;
int ans[A];
int n,m;
void dfs(int v, int p) {
    for(auto u : to[v]) {
        st.update(1, 0, n-1, pl[u], pr[u], 1);
    }
    if(!to[v].empty()) st.update(1, 0, n-1, pl[v], pr[v], 1);
    st.update(1, 0, n-1, pl[v], pl[v], 1);
    auto cur = st.get(1, 0, n-1, 0, n-1);
    if(cur.first == 0) ans[v] = n-1-cur.second;
    else ans[v] = n-1;
    st.update(1, 0, n-1, pl[v], pl[v], -1);
    for(auto u : g[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    for(auto u : to[v]) {
        st.update(1, 0, n-1, pl[u], pr[u], -1);
    }
    if(!to[v].empty()) st.update(1, 0, n-1, pl[v], pr[v], -1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    read(m);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0, 0);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        to[u].pb(v);
        to[v].pb(u);
    }
    st.build(n, 1, 0, n-1);
    dfs(0,0);
    forn(i,0,n) printf("%d ", ans[i]);
}