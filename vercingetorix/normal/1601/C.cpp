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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int INF = 1e9;
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
            t[v] = -tl;
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
        if (l>r) return -INF;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  max(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = max(t[v*2], t[v*2+1]);
        return ret;
    }
    
    int getr(int v, int tl, int tr) {
        push(v, tl, tr);
        if (t[v] <= 0) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int vr = getr(v*2+1,tm+1,tr);
        if (vr >= 0) return vr;
        return getr(v*2,tl,tm);
    }
    
    void go(int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl==tr) {
            cout<<t[v]<<' ';
            return;
        }
        int tm = (tl + tr) / 2;
        go(v*2,tl,tm);
        go(v*2+1,tm+1,tr);
    }
};

class streebas {
public:
    vi t;
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
    
    int get (int v, int tl, int tr, int l, int r) {
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
    
    void update (int v, int tl, int tr, int pos, int new_val) {
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
    
    int getr(int v, int tl, int tr, int k) {
        if(t[v] < k) return tr+1;
        if(tl==tr) return tl;
        int tm = (tl+tr)/2;
        if(t[v*2] >= k) return getr(v*2, tl, tm, k);
        else return getr(v*2+1,tm+1,tr,k-t[v*2]);
    }
};
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

ll numinv(vi & a) {
    int n = a.size();
    CoordinateCompressor comp;
    for(auto x : a) comp.add(x);
    comp.init();
    for(auto & x : a) x = comp.comp(x);
//    set<int> xx;
//    for(auto x : a) xx.insert(x);
//    unordered_map<int, int> comp;
//    int m = 0;
//    for(auto x : xx) comp[x] = m++;
    int m = comp.len();
    fenwick<int> fen(m);
    //    streebas st;
    //    st.build(vi(m, 0), 1, 0, m-1);
    ll ans = 0;
    for(int i = a.size(); i>0; i--) {
        //    for(auto x : a) {
        auto x = a[i-1];
        //        ans += fen.get(m-1) - fen.get(comp[x]);
        if(x > 0) ans += fen.get(x-1);
        fen.modify(x, 1);
        //        ans += st.get(1, 0, m-1, comp[x]+1, m-1);
        //        st.update(1, 0, m-1, comp[x], 1);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        readv(b,m);
        srt(b);
        stree st;
        st.build(n+1, 1, 0, n);
        vpi ev;
        forn(i,0,n) {
            ev.pb(mp(a[i], i));
            ev.pb(mp(a[i] + 1, i - n));
        }
        srt(ev);
        ll ans = 0;
        int pt = 0;
        for(auto x : b) {
            while(pt < ev.size() && ev[pt].first <= x) {
                if(ev[pt].second >= 0) {
                    int ind = ev[pt].second;
                    st.update(1, 0, n, ind+1, n, 1);
                }
                else {
                    int ind = ev[pt].second + n;
                    st.update(1, 0, n, 0, ind, -1);
                }
                pt++;
            }
            ans -= st.get(1, 0, n, 0, n);
        }
        printf("%lld\n", ans+numinv(a));
        
    }
    
    
}