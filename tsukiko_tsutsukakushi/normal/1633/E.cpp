/**
 *    author:  otera
 *    created: 05.02.2022 02:27:55 
**/
#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

namespace otera {
    template <typename T>
    struct Compressor {
        public:
            static constexpr int absent = -1;

            Compressor() : _xs(std::vector<T>{}) {}

            Compressor(const std::vector<T> &vs) {
                add(vs);
                build();
            }

            void add(const std::vector<T> &vs) {
                std::copy(vs.begin(), vs.end(), std::back_inserter(_xs));
            }

            void add(const T &e) {
                _xs.emplace_back(e);
            }

            void build() {
                std::sort(_xs.begin(), _xs.end());
                _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());
            }

            int size() const {
                return _xs.size();
            }

            bool has_key(const T &e) const {
                return std::binary_search(_xs.begin(), _xs.end(), e);
            }

            std::vector<int> get(const std::vector<T> &vs) const {
                std::vector<int> res;
                std::transform(vs.begin(), vs.end(), std::back_inserter(res), [&](const T &e) {
                    return get(e);
                });
                return res;
            }

            int get(const T &e, int default_value = absent) const {
                const int id = min_geq_index(e);
                return id != size() and _xs[id] == e ? id : default_value;
            }

            const T &operator[](int compressed_index) const {
                return _xs[compressed_index];
            }

            T min_gt(const T &e, const T &default_value) const {
                auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.end() ? default_value : *it;
            }
            T min_geq(const T &e, const T &default_value) const {
                auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.end() ? default_value : *it;
            }
            T max_lt(const T &e, const T &default_value) const {
                auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.begin() ? default_value : *std::prev(it);
            }
            T max_leq(const T &e, const T &default_value) const {
                auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.begin() ? default_value : *std::prev(it);
            }
            int min_gt_index(const T &e) const {
                return std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
            }
            int min_geq_index(const T &e) const {
                return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
            }
            int max_lt_index(const T &e) const {
                return int(std::lower_bound(_xs.begin(), _xs.end(), e)- _xs.begin()) - 1;
            }
            int max_leq_index(const T &e) const {
                return int(std::upper_bound(_xs.begin(), _xs.end(), e)- _xs.begin()) - 1;
            }
        private:
            std::vector<T> _xs;
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

typedef pair<ll, P> P2;

void solve() {
    INT(n, m);
    vvc<LP> g(n);
    vc<P2> es;
    rep(i, m) {
        INT(u, v); LL(w);
        w *= 2LL;
        -- u, -- v;
        g[u].eb(v, w);
        g[v].eb(u, w);
        es.eb(w, P{u, v});
    }
    // Sort(es);
    LL(p, k, a, b, c);
    vc<ll> cand;
    rep(i, m) cand.eb(es[i].fr);
    cand.eb(0);
    rep(i, m) {
        rep(j, i + 1, m) {
            cand.eb((es[i].fr + es[j].fr) / 2);
        }
    }
    otera::Compressor<ll> cmp(cand);
    vc<ll> ans(si(cmp), 0);
    vc<int> cnt(si(cmp), 0);
    rep(j, si(cmp)) {
        ll x = cmp[j];
        sort(all(es), [&](auto a, auto b) {
            if(abs(a.fr - x) == abs(b.fr - x)) {
                return a.fr > b.fr;
            }
            return abs(a.fr - x) < abs(b.fr - x);
        });
        atcoder::dsu uf(n);
        rep(i, m) {
            ll w = es[i].fr , u = es[i].sc.fr, v = es[i].sc.sc;
            // debug(w, x, u, v);
            if(!uf.same(u, v)) {
                uf.merge(u, v);
                ans[j] += abs(w - x);
                if(w <= x) ++ cnt[j];
            }
        }
        debug(j, x, ans[j], cnt[j]);
    }
    VEC(ll, q, p);
    ll res = 0;
    ll pre = -1;
    ll val = -1;
    rep(i, k) {
        if(i < p) val = q[i];
        else {
            val = (pre * a + b) % c;
        }
        int id = cmp.max_leq_index(val * 2);
        assert(cmp[id] <= 2 * val);
        ll tmp = ans[id] + abs(cmp[id] - val * 2) * (-n + 1 + 2 * cnt[id]);
        tmp /= 2;
        // debug(val, cmp[id], ans[id], cnt[id], tmp);
        debug(val, cmp[id]);
        debug(ans[id], cnt[id], tmp);
        res ^= tmp;
        pre = val;
    }
    out(res);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}