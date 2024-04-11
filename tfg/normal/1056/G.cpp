#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;
const int TT = 60000001;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

namespace io {
    // Source: StackOverflow
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }

    // I/O 
    
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        F0R(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
}

using namespace io;

int z = 0;
int val[TT], c[TT][2], sz[TT], nex = 1;

namespace treap {
    int tnode(int _val) {
        val[nex] = _val;
        sz[nex] = 1;
        return nex ++;
    }
    
    int copy(int x) {
        z ++; if (!x) return x;
        val[nex] = val[x];
        F0R(i,2) c[nex][i] = c[x][i];
        sz[nex] = sz[x];
        return nex ++;
    }
    
    int getsz(int x) { return x?sz[x]:0; }
    
    int recalc(int x) {
        sz[x] = 1+getsz(c[x][0])+getsz(c[x][1]);
        return x;
    }
    
    void tra(int x, vi& v) {
        if (!x) return;
        tra(c[x][0],v); v.pb(val[x]); tra(c[x][1],v);
    }
    
    pi splitsz(int t, int sz) {
        if (!t) return {t,t};
        auto T = copy(t);
        // cout << "AH " << t << " " << sz[t] << "\n";
        if (getsz(c[T][0]) >= sz) {
            auto p = splitsz(c[T][0], sz); c[T][0] = p.s;
            return {p.f, recalc(T)};
        } else {
            auto p = splitsz(c[T][1], sz-getsz(c[T][0])-1); c[T][1] = p.f;
            return {recalc(T), p.s};
        }
    }
        
    bool shouldLeft(int a, int b) {
        return rng() % (a+b) < a;
    }
    
    int merge(int L, int R, bool b = 0) {
        if (!L) return copy(R);
        if (!R) return copy(L);
        
        int t;
        if (shouldLeft(getsz(L),getsz(R))) {
            t = copy(L);
            c[t][1] = merge(c[L][1],R);
        } else {
            t = copy(R);
            c[t][0] = merge(L,c[R][0]);
        }
        return recalc(t);
    }
}

using namespace treap;

int n,m, NEX[MX][41]; 
ll s, t;

void brute() {
    if (s <= m) s += t;
    else s -= t;
    s %= n;
    while (s <= 0) s += n;
    t --;
}

int cur = 0;

int get(int l, int r) {
    while (l > n) l -= n, r -= n;
    while (l <= 0) l += n, r += n;
    if (r > n) return merge(get(l,n),get(n+1,r));
    auto a = splitsz(cur,r);
    auto b = splitsz(a.f,l-1);
    auto des = copy(b.s);
    cur = merge(merge(b.f,b.s),a.s);
    return des;
}

int build(vi& v, int l, int r) {
    if (l > r) return 0;
    int m = (l+r)/2;
    int root = tnode(v[m]);
    c[root][0] = build(v,l,m-1);
    c[root][1] = build(v,m+1,r);
    return recalc(root);
}

void gen() {
    FOR(i,1,n+1) cur = merge(cur, tnode(i));
    //cout << cur << " " << sz[cur] << ' ' << c[cur][0] << ' ' << c[cur][1] << "\n";
    //cout << sz[c[cur][0]] << " " << sz[c[cur][1]] << "\n";
    //auto a = splitsz(cur,5); cout << sz[a.f] << " " << sz[a.s]; exit(0);
    FOR(i,1,n) {
        int Z = z;
        auto a = get(i+1,i+m);
        auto b = get(m+1-i,n-i);
        if (getsz(a) != m || getsz(b) != n-m) {
            cout << "OOPS " << a << " " << b << " " << i << " " << getsz(a) << " " << getsz(b) << "\n";
            exit(0);
        }
        cur = merge(a,b);
    }
    // cout << z << "\n";
    vi v; tra(cur,v);
    F0R(i,sz(v)) NEX[i+1][0] = v[i];
}

int main() {
    // you should actually read the stuff at the bottom
    setIO(); re(n,m,s,t);
    gen();
    while (t % n != 0) brute();
    FOR(j,1,41) FOR(i,1,n+1) NEX[i][j] = NEX[NEX[i][j-1]][j-1];
    t /= n;
    F0Rd(i,41) if (t&(1LL<<i)) s = NEX[s][i];
    cout << s;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/