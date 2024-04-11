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

class stree {
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
            if(t[v] >= mod) t[v]-=mod;
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
                 ) % mod;
    }

    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] += new_val;
            if(t[v] >= mod) t[v]-=mod;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
            if(t[v] >= mod) t[v]-=mod;
        }
    }
    
    void set (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                set (v*2, tl, tm, pos, new_val);
            else
                set (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
            if(t[v] >= mod) t[v]-=mod;
        }
    }

};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        CoordinateCompressor comp;
        for(auto x : a) comp.add(x);
        comp.init();
        forn(i,0,n) a[i] = comp.comp(a[i]);
        int m = comp.len();
        vll l(n);
        vll r(n);
        stree stl;
        stl.build(vi(m,0), 1, 0, m-1);
        forn(i,0,n) {
            l[i] = stl.get(1, 0, m-1, 0, a[i]-1)+1;
            stl.update(1, 0, m-1, a[i], l[i]);
        }
        stree str;
        str.build(vi(m,0), 1, 0, m-1);
        for(int i = n-1; i>=0; i--) {
            r[i] = str.get(1, 0, m-1, a[i]+1, m-1)+1;
            str.update(1, 0, m-1, a[i], r[i]);
        }
        vpi inc;
        inc.pb(mp(0, n));
        for(int i = n-1; i>=0; i--) if(a[i] > inc.back().first) inc.pb(mp(a[i], i));
        ll ans = 0;
        vvi pos(m);
        forn(i,0,n) pos[a[i]].pb(i);
        stree st;
        st.build(vi(n,0), 1, 0, n-1);
        forn(it,1,inc.size()) {
            int f = inc[it-1].first;
            int to = inc[it].first;
//            forn(l,f,to) {
            for(int lev = to-1; lev>=f; lev--) {
                for(auto j : pos[lev]) {
                    int cur = (st.get(1, 0, n-1, j+1, n-1)+1)%mod;
                    st.set(1,0, n-1, j, cur);
                    ans = (ans + l[j] * (mod+r[j] - cur))%mod;
                }
            }
            for(int lev = to-1; lev>=f; lev--)
                for(auto j : pos[lev])
                    st.set(1,0,n-1, j, 0);
                    
        }
//        inc.pb(mp(1e9, -1));
//        vvi ev(m);

//        ll ans = 0;

//        forn(i,0,n) {
//            auto it = lower_bound(all(inc), mp(a[i]+1, 0)) - inc.begin();
//            int rp = inc[it].second;
//            if(rp < i) continue;
//            ev[inc[it].first - 1].pb(i);
//        }
//        forn(i,0,m) {
//            for(auto j : pos[i]) {
//                st.update(1, 0, n-1, j, st.get(1, 0, n-1, j+1, n-1)+1);
//            }
//            for(auto ind : ev[i]) {
//                ans = (ans + l[ind] * (mod+r[ind] - st.get(1, 0, n-1, ind, ind)))%mod;
//            }
//        }
        printf("%lld\n", ans);
        
    }
    
}