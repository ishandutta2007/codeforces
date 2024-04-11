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
const int INF = 2e9;

pi combine(const pi & a, const pi & b) {
    return mp(min(a.first, b.first), max(a.second, b.second));
}
class stree {
public:
    vi tn, tx;
    vi pp;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            tn = vi(n*4, INF);
            tx = vi(n*4, -INF);
            pp = vi(n*4, -1);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == -1) return;
        tx[v] = pp[v];
        tn[v] = pp[v];
        if(tl != tr) {
            pp[2*v] = pp[v];
            pp[2*v+1] = pp[v];
        }
        pp[v] = -1;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] = val;
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
            tx[v] = max(tx[v*2], tx[v*2+1]);
            tn[v] = min(tn[v*2], tn[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return mp(INF,-INF);
        if (tl ==l && r== tr)
            return mp(tn[v], tx[v]);
        int tm = (tl + tr) / 2;
        pi ret =  combine(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        tx[v] = max(tx[v*2], tx[v*2+1]);
        tn[v] = min(tn[v*2], tn[v*2+1]);
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
CoordinateCompressor comp;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, akgb;
    scanf("%d %d", &n, &akgb);
    vi l(n+2), r(n+2), h(n+2);
    vpi ord;
    forn(i,0,n) {
        scanf("%d %d %d", &h[i], &l[i], &r[i]);
        r[i]--;
        
    }
    l[n] = -INF;
    r[n] = INF;
    l[n+1] = -INF;
    r[n+1] = INF;
    h[n] = 0;
    h[n+1] = akgb;
    n+=2;
    forn(i,0,n) {
        comp.add(l[i]);
        comp.add(r[i]);
        ord.pb(mp(h[i], i));
    }
    comp.init();
    forn(i,0,n) {
        l[i] = comp.comp(l[i]);
        r[i] = comp.comp(r[i]);
    }
    srt(ord);
    stree st;
    int m = comp.len();
    st.build(m, 1, 0, m-1);
    vvi g(n);
    auto len = [&](int i, int j) {
        int mr = comp.xc[min(r[i], r[j])];
        int ml = comp.xc[max(l[i], l[j])];
        return max(0, mr-ml+1);
    };
    forn(ind,0,n) {
        int i = ord[ind].second;
        if(ind > 0) {
            int pl = l[i];
            int pr = r[i];
            int il = st.get(1, 0, m-1, pl, pl).first;
            int lto = min(r[i], r[il]);
            auto test = st.get(1, 0, m-1, pl, lto);
            if(test.first == test.second) {
                g[i].pb(il);
                
                if(lto == r[i]) {
                    st.update(1, 0, m-1, l[i], r[i], i);
                    continue;
                }
            }
            int ir = st.get(1, 0, m-1, pr, pr).first;
            int rto = max(l[i], l[ir]);
            test = st.get(1, 0, m-1, rto, pr);
            if(test.first == test.second) g[i].pb(ir);
        }
        st.update(1, 0, m-1, l[i], r[i], i);
    }
    st.build(m, 1, 0, m-1);
    forn(ind,0,n) {
        int i = ord[n-1-ind].second;
        if(ind > 0) {
            
            auto cur = st.get(1, 0, m-1, l[i], r[i]);
            if(cur.first == cur.second) {
                g[cur.first].pb(i);
            }
        }
        st.update(1, 0, m-1, l[i], r[i], i);
    }
    vi d(n,0);
    d[n-1] = INF;
    forn(ind,0,n) {
        int i = ord[n-1-ind].second;
        for(auto u : g[i]) {
            d[u] = max(d[u], min(d[i], len(i, u)));
        }
    }
    cout<<d[n-2];
}