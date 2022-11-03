/**
 *    author:  otera
 *    created: 04.04.2021 16:32:38 
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>=1;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define tpow(n) (1LL<<(n))
#define unless(A) if(!(A))
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

#define int long long

template<class T>
struct DualSegmentTree{
    virtual void c(T&, const T&) = 0;
    ll size = 1, rank = 0;
    vector<T> lazy;
    const T def_lazy;
    DualSegmentTree(ll n, const T& def_value, const T& def_lazy): def_lazy(def_lazy){
        while(size < n){
            size *= 2;
            rank++;
        }
        lazy.assign(size * 2, def_lazy);
        for(ll i = size; i < size * 2; i++) lazy[i] = def_value;
    }
    DualSegmentTree(const vector<T>& v, const T& def_lazy): def_lazy(def_lazy){
        while(size < v.size()){
            size *= 2;
            rank++;
        }
        lazy.assign(size * 2, def_lazy);
        for(ll i = 0; i < v.size(); i++) lazy[size + i] = v[i];
    }
    void push(ll at){
        if(!at) return;
        ll r = 31 - __builtin_clz(at);
        for(ll i = r; i > 0; i--){
            ll a = at >> i;
            if(lazy[a] != def_lazy){
                c(lazy[a * 2], lazy[a]);
                c(lazy[a * 2 + 1], lazy[a]);
                lazy[a] = def_lazy;
            }
        }
    }
    T operator[](ll at){
        at += size;
        push(at);
        return lazy[at];
    }
    void set(ll at, const T& val){
        at += size;
        push(at);
        lazy[at] = val;
    }
    void query(ll l, ll r, const T& val){
        if(l >= r) return;
        l += size;
        r += size;
        push(l >> __builtin_ctz(l));
        push((r >> __builtin_ctz(r)) - 1);
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) c(lazy[l++], val);
            if(r & 1) c(lazy[--r], val);
        }
    }
};
template<class T>
struct RAQ : DualSegmentTree<T>{
    using Base = DualSegmentTree<T>;
    void c(T& a, const T& b){ a += b; }
    RAQ(ll n, const T& def_value = T(), const T& def_lazy = T()) : Base(n, def_value, def_lazy){}
    RAQ(const vector<T>& v, const T& def_lazy = T()) : Base(v, def_lazy){}
};
template<class T>
struct RUQ : DualSegmentTree<T>{
    using Base = DualSegmentTree<T>;
    void c(T& a, const T& b){ a = b; }
    RUQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQ(const vector<T>& v, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_lazy){}
};
template<class T>
struct RchmQ : DualSegmentTree<T>{
    using Base = DualSegmentTree<T>;
    void c(T& a, const T& b){ chmin(a, b); }
    RchmQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RchmQ(const vector<T>& v, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_lazy){}
};

void solve() {
    INT(n);
    vc<ll> a(n), c(n);
    vc<ll> as;
    ll sum = 0;
    rep(i, n) {
        in(a[i], c[i]);
        as.pb(a[i]);
        sum += c[i];
    }
    vc<int> ids(n);
    iota(all(ids), 0);
    sort(all(ids), [&](int i, int j){ return a[i] < a[j];});
    Sort(as);
    RchmQ<ll> dp1(n, INF), dp2(n, INF);
    dp1.query(0, 1, 0);
    dp2.query(0, 1, -a[ids[0]]);
    rep(i, n - 1) {
        ll now = min(dp1[i], dp2[i] + a[ids[i]]);
        int p = ub(as, a[ids[i]] + c[ids[i]]);
        dp1.query(i + 1, p, now);
        dp2.query(p, n, now - a[ids[i]] - c[ids[i]]);
    }
    out(sum + min(dp1[n - 1], dp2[n - 1] + a[ids[n - 1]]));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}