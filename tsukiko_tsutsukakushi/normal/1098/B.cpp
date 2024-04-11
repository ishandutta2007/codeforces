/**
 *    author:  otera
 *    created: 25.12.2021 17:41:44 
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
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
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ print(*i); } }
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

const char C[4] = {'A', 'G', 'C', 'T'};

const int inf = 1'000'000'007;

void solve() {
    auto revc = [&](char x) -> int {
        rep(i, 4) {
            if(x == C[i]) return i;
        }
        assert(false);
    };
    auto calc = [&](int x, int y) -> P {
        P ret = {-1, -1};
        rep(i, 4) {
            if(i == x or i == y) continue;
            if(ret.fr == -1) ret.fr = i;
            else ret.sc = i;
        }
        return ret;
    };
    INT(n, m);
    VV(char, f, n, m);
    auto ans = f;
    int ma = 0;
    {
        vvvc<int> cnt(n, vvc<int>(2, vc<int>(4, 0)));
        rep(i, n) {
            rep(j, m) {
                int nj = j % 2;
                cnt[i][nj][revc(f[i][j])] ++;
            }
        }
        rep(a, 4) {
            rep(b, a + 1, 4) {
                auto [c, d] = calc(a, b);
                int res = 0;
                vvc<char> g(n, vc<char>(m));
                rep(i, n) {
                    if(i % 2 == 0) {
                        // a, b
                        int ab = cnt[i][0][a] + cnt[i][1][b], ba = cnt[i][0][b] + cnt[i][1][a];
                        if(ab > ba) {
                            rep(j, m) {
                                if(j % 2 == 0) g[i][j] = C[a];
                                else g[i][j] = C[b];
                            }
                            res += ab;
                        } else {
                            rep(j, m) {
                                if(j % 2 == 0) g[i][j] = C[b];
                                else g[i][j] = C[a];
                            }
                            res += ba;
                        }
                    } else {
                        // c, d
                        int cd = cnt[i][0][c] + cnt[i][1][d], dc = cnt[i][0][d] + cnt[i][1][c];
                        if(cd > dc) {
                            rep(j, m) {
                                if(j % 2 == 0) g[i][j] = C[c];
                                else g[i][j] = C[d];
                            }
                            res += cd;
                        } else {
                            rep(j, m) {
                                if(j % 2 == 0) g[i][j] = C[d];
                                else g[i][j] = C[c];
                            }
                            res += dc;
                        }
                    }
                }
                if(chmax(ma, res)) {
                    ans = g;
                }
            }
        }
    }
    {
        vvvc<int> cnt(m, vvc<int>(2, vc<int>(4, 0)));
        rep(i, n) {
            rep(j, m) {
                int ni = i % 2;
                cnt[j][ni][revc(f[i][j])] ++;
            }
        }
        rep(a, 4) {
            rep(b, a + 1, 4) {
                auto [c, d] = calc(a, b);
                int res = 0;
                vvc<char> g(n, vc<char>(m));
                rep(i, m) {
                    if(i % 2 == 0) {
                        // a, b
                        int ab = cnt[i][0][a] + cnt[i][1][b], ba = cnt[i][0][b] + cnt[i][1][a];
                        if(ab > ba) {
                            rep(j, n) {
                                if(j % 2 == 0) g[j][i] = C[a];
                                else g[j][i] = C[b];
                            }
                            res += ab;
                        } else {
                            rep(j, n) {
                                if(j % 2 == 0) g[j][i] = C[b];
                                else g[j][i] = C[a];
                            }
                            res += ba;
                        }
                    } else {
                        // c, d
                        int cd = cnt[i][0][c] + cnt[i][1][d], dc = cnt[i][0][d] + cnt[i][1][c];
                        if(cd > dc) {
                            rep(j, n) {
                                if(j % 2 == 0) g[j][i] = C[c];
                                else g[j][i] = C[d];
                            }
                            res += cd;
                        } else {
                            rep(j, n) {
                                if(j % 2 == 0) g[j][i] = C[d];
                                else g[j][i] = C[c];
                            }
                            res += dc;
                        }
                    }
                }
                if(chmax(ma, res)) {
                    ans = g;
                }
            }
        }
    }
    rep(i, n) {
        out(ans[i]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}