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

const ll inf = 1LL<<60;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

typedef pair<ll, tuple<int, int, int>> P2;

void solve() {
    INT(n, m);
    INT(p, q);
    VEC(string, s, n);
    vector dist(n, vector(m, vc<ll>(2, inf)));
    pqg<P2> pque;
    rep(i, n) {
        rep(j, m) {
            if(s[i][j] == '.') {
                dist[i][j][0] = 0;
                dist[i][j][1] = 0;
                pque.push(P2{0LL, make_tuple(i, j, 1)});
            }
        }
    }
    vector aite(n, vc<P>(m, P{-1, -1}));
    vector now(n, vc<int>(m, -1));
    rep(i, n) {
        rep(j, m) {
            if(i + 1 < n and (s[i][j] == 'U' and s[i + 1][j] == 'D')) {
                aite[i][j] = P{i + 1, j};
                aite[i + 1][j] = P{i, j};
                now[i][j] = 0;
                now[i + 1][j] = 0;
            }
            if(j + 1 < m and (s[i][j] == 'L' and s[i][j + 1] == 'R')) {
                aite[i][j] = P{i, j + 1};
                aite[i][j + 1] = P{i, j};
                now[i][j] = 1;
                now[i][j + 1] = 1;
            }
        }
    }
    while(pque.size()) {
        auto [di, pos] = pque.top(); pque.pop();
        auto [x, y, f] = pos;
        if(di > dist[x][y][f]) continue;
        if(f == 0) {
            auto [nx, ny] = aite[x][y];
            if(nx != -1) {
                if(chmin(dist[nx][ny][1], dist[x][y][0])) {
                    pque.push(P2{dist[nx][ny][1], make_tuple(nx, ny, 1)});
                }
            }
        }
        if(f == 1) {
            rep(k, 4) {
                int nx = x + dx[k], ny = y + dy[k];
                unless(0 <= nx and nx < n and 0 <= ny and ny < m) continue;
                int cost = (((k == 0 or k == 1) and now[nx][ny] == 0) or ((k == 2 or k == 3) and now[nx][ny] == 1) ? p : q);
                if(s[nx][ny] != '#') {
                    if(chmin(dist[nx][ny][0], dist[x][y][1] + cost)) {
                        pque.push(P2{dist[nx][ny][0], make_tuple(nx, ny, 0)});
                    }
                }
            }
        }
    }
    // rep(i, n) {
    //     rep(j, m) {
    //         cerr << dist[i][j][0] << " ";
    //     }
    //     cerr << endl;
    // }
    // rep(i, n) {
    //     rep(j, m) {
    //         cerr << dist[i][j][1] << " ";
    //     }
    //     cerr << endl;
    // }
    ll ans = inf;
    rep(i, n) {
        rep(j, m) {
            if(i + 1 < n and !(s[i][j] == 'U' and s[i + 1][j] == 'D') and s[i][j] != '#' and s[i + 1][j] != '#') {
                debug(i, j, i + 1, j, dist[i][j][1] + dist[i + 1][j][1]);
                chmin(ans, dist[i][j][1] + dist[i + 1][j][1]);
            }
            if(j + 1 < m and !(s[i][j] == 'L' and s[i][j + 1] == 'R') and s[i][j] != '#' and s[i][j + 1] != '#') {
                debug(i, j, i, j + 1, dist[i][j][1] + dist[i][j + 1][1]);
                chmin(ans, dist[i][j][1] + dist[i][j + 1][1]);
            }
        }
    }
    if(ans == inf) ans = -1;
    out(ans);
}

signed main() {
    int testcase = 1;
    // in(testcase);
    while(testcase--) solve();
    return 0;
}