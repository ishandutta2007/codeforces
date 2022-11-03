/**
 *    author:  otera
**/
#include<bits/stdc++.h>
using namespace std;

// #define int long long

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
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
#define unless(A) if(!(A))
ll intpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) { ll ans = 1; while (b) { if (b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
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
template<class T> void scan(T& a) { cin >> a; }
template<class T> void scan(vector<T>& a) { for (auto&& i : a) scan(i); }
void in() {}
template <class Head, class... Tail> void in(Head& head, Tail&... tail) { scan(head); in(tail...); }
void print() { cout << ' '; }
template<class T> void print(const T& a) { cout << a; }
template<class T> void print(const vector<T>& a) { if (a.empty()) return; print(a[0]); for (auto i = a.begin(); ++i != a.end(); ) { cout << ' '; print(*i); } }
int out() { cout << '\n'; return 0; }
template<class T> int out(const T& t) { print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail) { print(head); cout << ' '; out(tail...); return 0; }
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

#include <iostream>
#include <limits>
#include <vector>

#ifdef _MSC_VER
#  include <intrin.h>
#else
#  include <x86intrin.h>
#endif

namespace suisen {
class dynamic_bitset {
    public:
        explicit dynamic_bitset() {}
        explicit dynamic_bitset(const unsigned int n) {
            _bits.assign(outer_index(n) + 1, 0ULL);
        }
        inline int size() const {
            return _bits.size() * BLOCK_SIZE;
        }
        dynamic_bitset& operator|=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] |= other._bits[i];
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator&=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] &= other._bits[i];
            }
            _bits.erase(_bits.begin() + siz, _bits.end());
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator^=(const dynamic_bitset& other) {
            ensure_size(other.size());
            int siz = other._bits.size();
            for (int i = 0; i < siz; ++i) {
                _bits[i] ^= other._bits[i];
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator<<=(const unsigned int shamt) {
            if (size() == 0) return *this;
            int ishamt = outer_index(shamt);
            int lshamt = inner_index(shamt);
            if (lshamt) {
                ensure_size(size() + shamt);
                int rshamt = BLOCK_SIZE - lshamt;
                int siz = _bits.size();
                for (int i = siz - 1; i > ishamt; --i) {
                    _bits[i] = (_bits[i - ishamt] << lshamt) | (_bits[i - ishamt - 1] >> rshamt);
                }
                _bits[ishamt] = _bits[0] << lshamt;
                std::fill(_bits.begin(), _bits.begin() + ishamt, 0ULL);
            } else {
                _bits.insert(_bits.begin(), ishamt, 0ULL);
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset& operator>>=(const unsigned int shamt) {
            int ishamt = outer_index(shamt);
            if (ishamt >= _bits.size()) {
                _bits.clear();
                return *this;
            }
            int rshamt = inner_index(shamt);
            if (rshamt) {
                int lshamt = BLOCK_SIZE - rshamt;
                int sz = _bits.size();
                for (int i = 0; i + ishamt + 1 < sz; ++i) {
                    _bits[i] = (_bits[i + ishamt] >> rshamt) | (_bits[i + ishamt + 1] << lshamt);
                }
                _bits[sz - ishamt - 1] = _bits[sz - 1] >> rshamt;
                _bits.erase(_bits.end() - ishamt, _bits.end());
            } else {
                _bits.erase(_bits.begin(), _bits.begin() + ishamt);
            }
            cut_leading_zeros();
            return *this;
        }
        dynamic_bitset operator|(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) |= other;
        }
        dynamic_bitset operator&(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) &= other;
        }
        dynamic_bitset operator^(const dynamic_bitset& other) {
            return dynamic_bitset(_bits) ^= other;
        }
        dynamic_bitset operator<<(const unsigned int shamt) {
            return dynamic_bitset(_bits) <<= shamt;
        }
        dynamic_bitset operator>>(const unsigned int shamt) {
            return dynamic_bitset(_bits) >>= shamt;
        }
        bool operator[](const unsigned int n) const {
            if (n >= size()) return false;
            return (_bits[outer_index(n)] >> inner_index(n)) & 1;
        }
        void set(const unsigned int n, bool val = true) {
            if (not val and n >= size()) return;
            if (val) {
                ensure_size(n + 1);
                _bits[outer_index(n)] |= 1ULL << inner_index(n);
            } else {
                _bits[outer_index(n)] &= ~(1ULL << inner_index(n));
            }
        }
        void range_set(const unsigned int l, const unsigned int r, bool val = true) {
            if (not val and l >= size()) return;
            const int out_l = outer_index(l), out_r = outer_index(r - 1);
            const int in_l = inner_index(l), in_r = inner_index(r - 1);
            const unsigned long long mask_r = in_r == 63 ? ~0ULL : (1ULL << (in_r + 1)) - 1ULL;
            const unsigned long long mask_l = in_l == 0  ?  0ULL : (1ULL << in_l) - 1ULL;
            if (val) {
                ensure_size(r + 1);
                if (out_l < out_r) {
                    _bits[out_l] |= ~0ULL ^ mask_l;
                    for (int i = out_l + 1; i <= out_r - 1; ++i) {
                        _bits[i] = ~0ULL;
                    }
                    _bits[out_r] |= mask_r;
                } else {
                    _bits[out_l] |= mask_r ^ mask_l;
                }
            } else {
                if (out_l < out_r) {
                    _bits[out_l] &= mask_l;
                    for (int i = out_l + 1; i <= out_r - 1; ++i) {
                        _bits[i] = 0ULL;
                    }
                    _bits[out_r] &= ~mask_r;
                } else {
                    _bits[out_l] &= ~(mask_r ^ mask_l);
                }
                cut_leading_zeros();
            }
        }
        void clear() {
            _bits.clear();
        }
        void flip(const unsigned int n) {
            ensure_size(n + 1);
            _bits[outer_index(n)] ^= 1ULL << inner_index(n);
        }
        __attribute__((target("avx2")))
        int count() const {
            int res = 0;
            for (unsigned long long e : _bits) res += _mm_popcnt_u64(e);
            return res;
        }
        friend std::ostream& operator<<(std::ostream &out, const dynamic_bitset &bs) {
            std::string res;
            for (auto it = bs._bits.rbegin(); it != bs._bits.rend(); ++it) {
                unsigned long long bits = *it;
                for (int j = BLOCK_SIZE - 1; j >= 0; --j) {
                    res += char('0' + ((bits >> j) & 1));
                }
            }
            out << res;
            return out;
        }
        const std::vector<unsigned long long>& data() const {
            return _bits;
        }
    private:
        static constexpr unsigned int BLOCK_SIZE = std::numeric_limits<unsigned long long>::digits;
        static constexpr unsigned int LOG_BLOCK_SIZE = __builtin_ctz(BLOCK_SIZE);
    
        std::vector<unsigned long long> _bits;

        dynamic_bitset(const std::vector<unsigned long long> &bits) : _bits(bits) {}

        static constexpr unsigned int outer_index(unsigned int k) {
            return k >> LOG_BLOCK_SIZE;
        }
        static constexpr unsigned int inner_index(unsigned int k) {
            return k & (BLOCK_SIZE - 1);
        }
        void ensure_size(const unsigned int n) {
            int old_size = _bits.size();
            int new_size = outer_index(n == 0 ? n : n - 1) + 1;
            if (new_size > old_size) {
                _bits.resize(new_size, 0ULL);
            }
        }
        void cut_leading_zeros() {
            while (_bits.size() and _bits.back() == 0ULL) _bits.pop_back();
        }
};
} // namespace suisen

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_{};

constexpr ll INF = 1LL << 60;

constexpr int N = 26;
constexpr int B = 200'200;

void solve() {
    INT(n, m, k);
    STR(s);
    vc<int> cnt(N, 0);
    rep(i, k) {
        cnt[s[i] - 'A'] ++;
    }
    ll ans = INF;
    rep(i, N) {
        suisen::dynamic_bitset dp;
        dp.set(0, 1);
        int sum = 0;
        rep(j, N) {
            if (i == j) continue;
            dp |= (dp << cnt[j]);
            if (dp.size() > n + 1) {
                dp.range_set(n + 1, dp.size(), false);
            }
            sum += cnt[j];
        }
        for (int x = 0; x <= cnt[i]; ++x) {
            if (n - x >= 0 and dp[n - x]) {
                int can = sum - (n - x);
                if (can >= m) {
                    chmin(ans, 0LL);
                    break;
                } else {
                    int need = m - can;
                    if (need <= cnt[i] - x) chmin(ans, (ll) x * need);
                }
            }
        }
    }
    out(ans);
}

signed main() {
    int testcase = 1;
    in(testcase);
    while (testcase--) solve();
    return 0;
}