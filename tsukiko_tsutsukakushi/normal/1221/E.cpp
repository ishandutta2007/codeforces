/**
 *    author:  otera
 *    created: 02.02.2022 07:10:41 
**/
#include<bits/stdc++.h>
namespace otera{
    template <typename Container>
    class RunLength {
        public:
            using content_type = typename Container::value_type;
            using value_type = std::pair<content_type, long long>;
            RunLength(const Container &c) noexcept {
                _compressed = compress(c);
            }

            void clear() {
                _compressed.clear();
            }

            int size() const noexcept {
                return (int)_compressed.size();
            }
            const value_type &operator[](int compressed_index) const {
                return _compressed[compressed_index];
            }

            auto begin()   const noexcept { return _compressed.begin();   }
            auto end()     const noexcept { return _compressed.end();     }
            auto rbegin()  const noexcept { return _compressed.rbegin();  }
            auto rend()    const noexcept { return _compressed.rend();    }

            void push_back(const content_type &val, const long long cnt = 1) {
                if (_compressed.size() and _compressed.back().first == val) {
                    _compressed.back().second += cnt;
                } else {
                    _compressed.emplace_back(val, cnt);
                }
            }

            void pop_back(long long cnt = 1) {
                while(_compressed.size() and cnt > 0) {
                    if(cnt < _compressed.back().second) {
                        _compressed.back().second -= cnt;
                        cnt = 0;
                    } else {
                        cnt -= _compressed.back().second;
                        _compressed.pop_back();
                    }
                }
            }

            static std::vector<value_type> compress(const Container &c) {
                std::vector<value_type> res;
                for(auto ite_l = c.begin(), ite_r = c.begin(); ite_l != c.end(); ite_l = ite_r) {
                    while (ite_r != c.end() and *ite_l == *ite_r) ++ite_r;
                    res.emplace_back(*ite_l, ite_r - ite_l);
                }
                return res;
            }
        private:
            std::vector<value_type> _compressed;
    };
} // namespace otera
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
    INT(a, b);
    assert(a > b);
    STR(s);
    int n = si(s);
    otera::RunLength<string> rl(s);
    int sz = si(rl);
    vc<int> cs;
    int cnt = 0;
    rep(i, sz) {
        if(rl[i].fr == '.') {
            if(b <= rl[i].sc and rl[i].sc < a) {
                out("NO");
                return;
            }
            if(rl[i].sc >= a) cs.eb(rl[i].sc);
            if(rl[i].sc >= 2 * b) {
                ++ cnt;
            }
        }
    }
    dump(cs);
    if(si(cs) == 0 or cnt >= 2) {
        out("NO");
        return;
    }
    if(cnt == 0) {
        if(si(cs) % 2 == 0) {
            out("NO");
        } else {
            out("YES");
        }
        return;
    }
    if(cnt == 1) {
        Sort(cs); Rev(cs);
        assert(cs[0] >= 2 * b);
        assert(cs[0] >= a);
        for(int i = 1; i < si(cs); ++ i) {
            assert(a <= cs[i] and cs[i] < 2 * b);
        }
        for(int i = 0; i + a <= cs[0]; ++ i) {
            int x = i;
            int y = cs[0] - (i + a);
            if(x >= 2 * b or y >= 2 * b) continue;
            if(b <= x and x < a) continue;
            if(b <= y and y < a) continue;
            int sum = si(cs) - 1 + (a <= x and x < 2 * b) + (a <= y and y < 2 * b);
            if(sum % 2 == 0) {
                out("YES");
                return;
            }
        }
        out("NO");
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    INT(t); rep(i, t)solve();
    // solve();
    return 0;
}