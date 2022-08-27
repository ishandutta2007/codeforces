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
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
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
    
    T get(int l, int r) {
        T ret = get(r);
        if (l>0) ret -= get(l-1);
        return ret;
    }
};
class CoordinateCompressor {
public:
    vi xc;
    vi xx;
    
    inline void add(int x) {
        xx.pb(x);
    }
    
    void init() {
        xc.clear();
        srt(xx);
        forn(i,0,xx.size()) if(i==0 || xx[i] != xx[i-1]) xc.pb(xx[i]);
    }
    
    inline int comp(const int x) {
        return lower_bound(all(xc), x) - xc.begin();
    }
    
    inline int len() {
        return xc.size();
    }
};

struct sega {
    int num = 0;
    ll sum = 0;
    ll ladder = 0;
    sega() {};
    sega(int v) : num(1), sum(v), ladder(0) {};
    void clear() {
        num = 0;
        sum = 0;
        ladder = 0;
    }
};

sega combine(const sega & a, const sega & b) {
    sega ret;
    ret.num = a.num + b.num;
    ret.sum = a.sum + b.sum;
    ret.ladder = a.ladder + b.ladder + b.sum * a.num;
    return ret;
};

class stree {
public:
    vector<sega> t;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = sega(a[tl]);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    sega get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return sega();
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  combine(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            if(new_val == -1) t[v].clear();
            else t[v] = sega(new_val);
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  combine(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    CoordinateCompressor comp;
    forn(i,0,n) comp.add(a[i]);
    comp.init();
    forn(i,0,n) a[i] = comp.comp(a[i]);
    int m = comp.len();
    vi al(n), ar(n);
    fenwick<int> fen(m);
    forn(i,0,n) {
        al[i] = fen.get(0, a[i]);
        fen.modify(a[i], 1);
    }
    fen = fenwick<int>(m);
    for(int i = n-1; i>=0; i--) {
        ar[i] = fen.get(0, a[i]);
        fen.modify(a[i], 1);
    }
    vvi pos(m);
    forn(i,0,n) pos[a[i]].pb(i);
    vi w(n);
    forn(i,0,m) forn(j,0,pos[i].size()) w[pos[i][j]] = j;
    vector<stree> l(m), r(m);
    ll ans = 0;
    forn(it,0,m) {
        vi curl, curr;
        int cn = pos[it].size();
        forn(i,0,cn) {
            curl.pb(al[pos[it][i]]);
            curr.pb(ar[pos[it][i]]);
        }
        l[it].build(curl, 1, 0, cn-1);
        r[it].build(curr, 1, 0, cn-1);
        forn(i,0,cn) {
            auto sl = l[it].get(1, 0, cn-1, 0, i-1);
            auto sr = r[it].get(1, 0, cn-1, i+1, cn-1);
            ans = (ans+sl.sum %mod* (sr.sum%mod))%mod;
        }
    }
    int qn;
    scanf("%d", &qn);
    forn(iaf,0,qn) {
        int tp, v;
        scanf("%d %d", &tp, &v);
        v--;
        int it = a[v];
        int i = w[v];
        int cn = pos[a[v]].size();
        auto sl = l[it].get(1, 0, cn-1, 0, i-1);
        auto sr = r[it].get(1, 0, cn-1, i+1, cn-1);
        if(sl.num > 0) {
            sl.ladder = (sl.num - 1) * sl.sum - sl.ladder;
        }
        sl.sum %= mod;
        sr.sum %= mod;
        sl.ladder %= mod;
        sr.ladder %= mod;
        int k = tp*2-3;
        ans = (ans + mod + sl.sum * sr.sum % mod * k) % mod;
        ans = (ans + mod + al[v] * sr.ladder % mod * k) % mod;
        ans = (ans + mod + ar[v] * sl.ladder % mod * k) % mod;
        if (tp == 1) {
            l[it].update(1, 0, cn-1, i, -1);
            r[it].update(1, 0, cn-1, i, -1);
        }
        else {
            l[it].update(1, 0, cn-1, i, al[v]);
            r[it].update(1, 0, cn-1, i, ar[v]);
        }
        printf("%lld\n", ans);
    }
    
    
}