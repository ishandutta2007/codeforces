#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;
using ld = long double;
using cd = complex<ld>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;

using vi  = vector<int>;
using vd  = vector<ld>;
using vl  = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vcd = vector<cd>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define F first
#define S second

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 998244353;
const ll LINF = 1e18;
const int INF = 1e9;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.F,p.S); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.F,", ",x.S,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}
 
using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

/*                                        *
 *                                        *
 *                  B               *
 *                                        *
 *                                        */

const int N = 1e5+7;
 
struct SGT {
    int n, t[2*N];

    SGT(int n) : n(n) {
        fill(t, t+2*n, INF);
    }
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    
    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
    }
    
    int query(int l, int r) {  // sum on interval [l, r)
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = min(t[l++], res);
            if (r&1) res = min(t[--r], res);
        }
        return res;
    }
};

int calc(int f, int n, int m, SGT& a) {
    return f+m > n ? min(a.query(f, n), a.query(0, f+m-n)) : a.query(f, f+m);
}

int main() {
    setIO(); // fast IO
    int n; re(n); vpi v(n);
    SGT a(n), b(n);
    for(int i = 0; i < n; ++i)
        re(v[i].F), v[i].S = i, a.t[i+n] = INF, b.t[i+n] = v[i].F;
    
    a.build(), b.build(), sort(all(v), greater<pi>());
    vi d(n);

    bool first = true;
    for(auto x : v) {
        if(first) {
            first = false;
            int mx = x.F, i = (x.S+1)%n; int j = 1;
            for(; i != x.S; ckmax(mx, b.t[n + i++]), i=i>=n?i-n:i)
                if(mx > 2*b.t[n + i]) { --i; j = 0; break; }
            //ps(x.F, x.S, i, j);
            d[x.S] = i==x.S&&j>0 ? -1 : (i-x.S+n+1)%n;
        }
        else {
            int id = a.query(x.S, n);
            int len = id - x.S;
            if(id == INF) id = a.query(0, n), len = n-x.S+id;
            //ps(x.S, x.F, len);
            int l = 1, r = len;
            while(l < r) {
                int m = (l+r+1)/2;
                if(calc(x.S, n, m, b)*2 < x.F) r = m-1;
                else l = m;
            }
            if(r == len) d[x.S] = d[id] < 0 ? d[id] : len + d[id]; 
            else d[x.S] = r;
        }
        a.modify(x.S, x.S);
    }
    for(int x : d) pr(x, ' ');
}