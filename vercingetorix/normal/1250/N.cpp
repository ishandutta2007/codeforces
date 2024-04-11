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
const int A = 50;
#else
const int A = 500500;
#endif
const int INF = 2e9;
int n;
int h[A];
vi g[A];
vi ch[A];
int par[A];
int st[A];
vi miners;

void dfsp(int v, int p) {
    par[v] = v;
    st[v] = 1;
    for(auto u : g[v]) {
        if(u == p) continue;
        ch[v].pb(u);
        dfsp(u, v);
        st[v] += st[u];
    }
}

multiset<int> stamp;
multiset<int> s;
set<pi> q;
int ans = INF;
void fill1() {
    while(!miners.empty() && miners.back() <= -q.begin()->first) {
        int i = q.begin()->second;
        q.erase(q.begin());
        miners.pop_back();
        for(auto v : ch[i]) q.insert(mp(-h[v], v));
    }
}

vi kill;
int fire;
int curl = -1;

class stree {
public:
    vi t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = n-tl;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
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
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return -INF;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = max(t[v*2], t[v*2+1]);
        return ret;
    }
};

stree fall;
int m;

void dfsfill(int v, int mh, int add) {
    int curh = min(mh, h[v]);
    int to = lower_bound(all(miners), curh+1) - miners.begin();
    fall.update(1, 0, m-1, 0, to-1, add);
    for(auto u : ch[v]) dfsfill(u, curh, add);
}

void solve() {
    m = miners.size();
    fall.build(m, 1, 0, m-1);
    for(auto x : kill) {
        dfsfill(x, INF, -1);
    }
    for(auto x : kill) {
        dfsfill(x, INF, 1);
        int wash = h[x];
        h[x] = fire;
        dfsfill(x, INF, -1);
        if(fall.get(1, 0, m-1, 0, m-1) <= 0) ans = min(ans, fire-wash);
        dfsfill(x, INF, 1);
        h[x] = wash;
        dfsfill(x, INF, -1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n) scanf("%d", &h[i]);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfsp(0,0);
    int k;
    read(k);
    q.insert(mp(-h[0], 0));
    while(k--) {
        int x;
        read(x);
        miners.pb(x);
    }
    srt(miners);
    fill1();
    if(miners.empty()) {
        cout<<0;
        exit(0);
    }
    fire = miners.back();
    for(auto x : q) kill.pb(x.second);
    for(auto x : miners) s.insert(x);
    solve();
    if(ans == INF) ans = -1;
    printf("%d", ans);
    
}