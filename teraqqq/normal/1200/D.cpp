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
        pr("{",x.f,", ",x.s,"}"); 
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
 *                  D               *
 *                                        *
 *                                        */

int n, k;

int main() {
    setIO(); // fast IO
    re(n, k);
    vector<string> s(n); re(s);
    vector<vi> d(n, vi(n));
    vi mnc(n, n), mxc(n, -1), mnr(n, n), mxr(n, -1);

    for(int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j) {
        if(s[i][j] == 'B') {
            ckmin(mnc[j], i), ckmax(mxc[j], i);
            ckmin(mnr[i], j), ckmax(mxr[i], j);
        }
    }

    int add = 0;
    for(int i = 0; i < n; ++i) {
        //ps("Column #", i, " ::: ", mnc[i], " to ", mxc[i]);
        if(mxc[i] < 0) ++add;
        else if(mxc[i] - mnc[i] < k) {
            int a1 = max(0, i-k+1), a2 = max(0, mxc[i]-k+1);
            int b1 = i+1, b2 = mnc[i]+1;
            d[a1][a2]++;
            if(b2 < n) d[a1][b2]--;
            if(b1 < n) d[b1][a2]--;
            if(b1 < n && b2 < n) d[b1][b2]++;
            //pr("Collum #", i, " => ");
            //ps("add : ", a1, ":", a2, " - ", b1-1, ":", b2-1);
        }

        //ps("Row #", i, " ::: ", mnr[i], " to ", mxr[i]);
        if(mxr[i] < 0) ++add;
        else if(mxr[i] - mnr[i] < k) {
            int a2 = max(0, i-k+1), a1 = max(0, mxr[i]-k+1);
            int b2 = i+1, b1 = mnr[i]+1;
            d[a1][a2]++;
            if(b2 < n) d[a1][b2]--;
            if(b1 < n) d[b1][a2]--;
            if(b1 < n && b2 < n) d[b1][b2]++;
            //pr("Row #", i, " => ");
            //ps("add : ", a1, ":", a2, " - ", b1-1, ":", b2-1);
        }
    }
/*
    ps(add);
    for(int i = 0; i < n; ++i, ps()) 
    for(int j = 0; j < n; ++j) {
        pr(d[i][j], ' ');
    } ps();
*/

    int res = 0;
    for(int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j) {
        if(i) d[i][j] += d[i-1][j];
        if(j) d[i][j] += d[i][j-1];
        if(i && j) d[i][j] -= d[i-1][j-1];
        ckmax(res, d[i][j]);
        //pr(d[i][j], ' ');
    }

    ps(res+add);
}