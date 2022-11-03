/**
 *    author:  otera
 *    created: 01.03.2021 07:04:36 
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
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
#define si(a) (int)a.size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
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
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }

void yes() {
    out("YES");
    exit(0);
}

void no() {
    out("NO");
    exit(0);
}

void solve() {
    INT(n);
    vector<vector<pair<int, bool>>> g(n, vector<pair<int,bool>>());
    rep(i, n - 1) {
        INT(u, v); -- u, -- v;
        g[u].pb({v, 1});
        g[v].pb({u, 1});
    }
    vector<int> fib = {1, 1};
    while(fib.back() < n) {
        int now = fib[si(fib) - 1] + fib[si(fib) - 2];
        fib.pb(now);
    }
    if(fib.back() != n) no();
    vector<int> sz(n, 0);
    auto dfs = [&](auto &&self, int v, int pa) -> void {
        sz[v] = 1;
        for(auto p: g[v]) {
            if(!p.sc) continue;
            int nv = p.fr;
            if(nv == pa) continue;
            self(self, nv, v);
            sz[v] += sz[nv];
        }
    };
    auto ddfs = [&](auto &&self, int v, int pa, int k, int &pu, int &pv, int &pk) -> void {
        if(pu != -1) return;
        for(auto p: g[v]) {
            if(!p.sc) continue;
            int nv = p.fr;
            if(nv == pa) continue;
            if(sz[nv] == fib[k - 1] or sz[nv] == fib[k - 2]) {
                pu = v, pv = nv;
                pk = (sz[nv] == fib[k - 1] ? k - 1 : k - 2);
                break;
            }
            self(self, nv, v, k, pu, pv, pk);
        }
    };
    auto check = [&](auto &&self,int v, int k) -> void {
        // out(v, k);
        if(k <= 1) return;
        dfs(dfs, v, -1);
        int pu = -1, pv = -1, pk = -1;
        ddfs(ddfs, v, -1, k, pu, pv, pk);
        // out(v, k, pu, pv, pk);
        if(pu == -1) no();
        for(auto& p: g[pu]) {
            if(p.fr == pv) {
                p.sc = 0;
            }
        }
        for(auto& p: g[pv]) {
            if(p.fr == pu) {
                p.sc = 0;
            }
        }
        self(self, pv, pk);
        self(self, pu, (pk == k - 1 ? k - 2 : k - 1));
    };
    check(check, 0, si(fib) - 1);
    yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}