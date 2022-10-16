#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

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
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
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
 *                  F               *
 *                                        *
 *                                        */
 
const int M = 9*8*7*5;
const int N = 1007;
 
int n, k[N], m[N], t[N][M];
vector<int> mv[N];
 
void calcRoad(int i, int j) {
    vector<pi> vv;
    set<int> sv;
    while(t[i][j] == 0) {
        vv.push_back({i, j});
        t[i][j] = -1;
        j = (j+k[i])%M;
        i = mv[i][j%m[i]];
 
    }
 
    int res;
    if(t[i][j] == -1) {
        while(t[i][j] == -1) {
            t[i][j] = -2; sv.insert(i);
            j = (j+k[i])%M;
            i = mv[i][j%m[i]];
        }
        res = sv.size();
    }
    else res = t[i][j];
    for(pi x : vv) t[x.F][x.S] = res;
}
 
int main() {
    setIO(); // fast IO
    re(n);
    for(int i = 0; i < n; ++i) 
        re(k[i]), k[i] = (k[i]%M+M)%M;
    for(int i = 0; i < n; ++i) {
        re(m[i]); mv[i] = vi(m[i]); re(mv[i]);
        for(int& j : mv[i]) --j;
    }
 
    for(int i = 0; i < n; ++i) 
    for(int j = 0; j < M; ++j)
        if(t[i][j] == 0) calcRoad(i, j);
    
    int q; re(q);
    while(q--) {
        int i, j; re(i, j);
        j = (j%M+M)%M;
        ps(t[i-1][j]);
    }
}