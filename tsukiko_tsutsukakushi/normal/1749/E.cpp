/**
 *    author:  otera
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using int128_t = __int128_t;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define rev_repa(i, n) for(int i=n-1;i>=0;i--)
#define rev_repb(i, a, b) assert(a > b);for(int i=a;i>b;i--)
#define rev_rep(...) overload3(__VA_ARGS__, rev_repb, rev_repa)(__VA_ARGS__)
#define rev_rep1a(i, n) for(int i=n;i>=1;i--)
#define rev_rep1b(i, a, b) assert(a >= b);for(int i=a;i>=b;i--)
#define rev_rep1(...) overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(), c.rend()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
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
template <class T, class U> using umap = unordered_map<T, U>;
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

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_ {};

const int inf = 1e9 + 7;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int ddx[8] = {-1, -1, 0, 1, 1, -1, 0, 1};
const int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
    INT(n, m);
    auto inside = [&](int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < m;
    };
    auto adj = [&](int i, int j, int ni, int nj) -> bool {
        rep(k, 4) {
            if(i + dx[k] == ni and j + dy[k] == nj) return true;
        }
        return false;
    };
    VEC(string, s, n);
    vvc<int> di(n, vc<int>(m, inf));
    vvc<bool> ok(n, vc<bool>(m, 1));
    rep(i, n) {
        rep(j, m) {
            rep(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                if(inside(ni, nj) and s[ni][nj] == '#') {
                    ok[i][j] = 0;
                }
            }
        }
    }
    deque<P> deq;
    rep(i, n) {
        if(s[i][0] == '#') {
            di[i][0] = 0;
            deq.push_front(P{i, 0});
        } else if(ok[i][0]) {
            di[i][0] = 1;
            deq.push_back(P{i, 0});
        }
    }
    vvc<P> pre(n, vc<P>(m, P{-1, -1}));
    while(deq.size()) {
        auto [x, y] = deq.front(); deq.pop_front();
        rep(k, 8) {
            int nx = x + ddx[k], ny = y + ddy[k];
            if(inside(nx, ny)) {
                if(s[nx][ny] == '#') {
                    if(chmin(di[nx][ny], di[x][y])) {
                        deq.push_front(P{nx, ny});
                        pre[nx][ny] = P{x, y};
                    }
                } else if(ok[nx][ny]) {
                    if(s[x][y] == '.' and s[nx][ny] == '.' and adj(x, y, nx, ny)) continue;
                    if(chmin(di[nx][ny], di[x][y] + 1)) {
                        deq.push_back(P{nx, ny});
                        pre[nx][ny] = P{x, y};
                    }
                }
            }
        }
    }
    int ans = inf;
    int cx = -1;
    rep(i, n) {
        if(chmin(ans, di[i][m - 1])) {
            cx = i;
        }
    }
    if(ans == inf) out("NO");
    else {
        out("YES");
        rep(i, n) {
            dump(di[i]);
        }
        vc<string> res = s;
        int cy = m - 1;
        int now = ans;
        vvc<bool> used(n, vc<bool>(m, 0));
        while(1) {
            res[cx][cy] = '#';
            used[cx][cy] = 1;
            if(cy == 0 and (s[cx][cy] == '#' or ok[cx][cy])) break;
            debug(cx, cy);
            int cost = (s[cx][cy] == '#' ? 0 : 1);
            auto [nx, ny] = pre[cx][cy];
            cx = nx, cy = ny;
        }
        res[cx][cy] = '#';
        rep(i, n) {
            out(res[i]);
        }
    }
}

signed main() {
    int testcase = 1;
    in(testcase);
    while(testcase--) solve();
    return 0;
}