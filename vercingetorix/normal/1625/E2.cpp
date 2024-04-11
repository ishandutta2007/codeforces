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

class stree {
public:
    vll t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) +
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr)
            t[v] += new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
};

int n,q;
#ifdef LOCAL
const int A = 20;
#else
const int A = 300500;
#endif
int par[A];
vi ch[A];
ll num[A];
int chnum[A];
vll pref[A];
stree st;

template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n = 0) : n(_n) {
        fenw.resize(n);
    }
    
    void resize(int _n) {
        n = _n;
        fenw = vector<T>(n, 0);
    }
    
    void modify(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

fenwick<int> fen[A];

void dfs(int v) {
    num[v] = ll(ch[v].size())*(ch[v].size() + 1)/2;
    st.update(1, 0, n, v, num[v]);
    ll sum = 0;
    for(auto u : ch[v]) {
        dfs(u);
    }
    fen[v].resize(ch[v].size());
    forn(i,0,ch[v].size()) fen[v].modify(i, 1);
}
vi l, r;

ll get(int sl, int sr) {
    int p = par[sl];
    int il = chnum[sl];
    int ir = chnum[l[sr-1] + 1];
    ll ans = st.get(1, 0, n, sl, sr);
    ll k = fen[p].get(ir);
    if(il > 0) k -= fen[p].get(il-1);
    ans += k*(k+1)/2;
    return ans;
}

void del(int sl) {
    int p = par[sl];
    int il = chnum[sl];
    int kwas = fen[p].get(ch[p].size()-1);
    fen[p].modify(il, -1);
    st.update(1, 0, n, p, -kwas);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &q);
    st.build(vi(n+1,0), 1, 0, n);
    char c[300500];
    scanf("%s", c);
    vi op;
    //    vi l(n,-1);
    //    vi r(n,-1);
    l = vi(n,-1);
    r = vi(n,-1);
    forn(i,0,n) {
        if(c[i] == '(') op.pb(i);
        else {
            if(!op.empty()) {
                l[i] = op.back();
                r[op.back()] = i;
                op.pop_back();
                if(op.empty()) {
                    par[l[i] + 1] = 0;
                }
                else {
                    par[l[i] + 1] = op.back() + 1;
                }
                ch[par[l[i] + 1]].pb(l[i] + 1);
            }
        }
    }
    for(auto bad : op) {
        for(auto son : ch[bad + 1]) {
            par[son] = 0;
            ch[0].pb(son);
        }
        ch[bad + 1].clear();
    }
    forn(i,0,n+1) forn(j,0,ch[i].size()) chnum[ch[i][j]] = j;
    dfs(0);
    
    forn(i,0,q) {
        int tp, sl, sr;
        scanf("%d %d %d", &tp, &sl, &sr);
        if(tp == 2) {
            
            printf("%lld\n", get(sl, sr));
        }
        else {
            del(sl);
        }
    }
    
    
    
    
}