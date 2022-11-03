/**
 *    author:  otera
 *    created: 06.04.2021 01:34:32 
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

void solve() {
    INT(n, m);
    vvc<tuple<int, int, int>> g(n);
    rep(i, m) {
        INT(u, v, w); -- u, -- v;
        g[u].eb(v, w, i);
        g[v].eb(u, w, i);
    }
    INT(q);
    vvc<LP> h(n);
    rep(i, q) {
        INT(u, v, l); -- u, -- v;
        h[u].eb(v, l);
        h[v].eb(u, l);
    }
    vv(ll, di, n, n, INF);
    rep(i, n) {
        di[i][i] = 0;
        for(auto e: g[i]) {
            int j = get<0>(e);
            chmin(di[i][j], get<1>(e));
        }
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                chmin(di[i][j], di[i][k] + di[k][j]);
            }
        }
    }
    vec(int, useful, m, 0);
    rep(u, n) {
        // vc<ll> dist(n, INF);
        // pqg<LP> pque;
        // for(auto p: h[u]) {
        //     chmin(dist[p.fr], -p.sc);
        //     pque.push({dist[p.fr], p.fr});
        // }
        // while(pque.size()) {
        //     auto p = pque.top(); pque.pop();
        //     int v = p.sc; ll d = p.fr;
        //     if(d > dist[v]) continue;
        //     for(auto e: g[v]) {
        //         int nv = get<0>(e); ll w = get<1>(e);
        //         if(chmin(dist[nv], d + w)) {
        //             pque.push({d + w, nv});
        //         }
        //     }
        // }
        // rep(a, n) {
        //     for(auto e: g[a]) {
        //         int b = get<0>(e), w = get<1>(e), id = get<2>(e);
        //         if(dist[b] <= - di[u][a] - w) useful[id] = 1;
        //     }
        // }
        vc<ll> dist(n, INF);
        rep(b, n) {
            for(auto p: h[u]) {
                int v = p.fr, l = p.sc;
                chmin(dist[b], -l + di[v][b]);
            }
            for(auto e: g[b]) {
                int a = get<0>(e), w = get<1>(e), id = get<2>(e);
                if(dist[b] <= -di[u][a] - w) useful[id] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, m) {
        if(useful[i]) ++ ans;
    } 
    out(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}