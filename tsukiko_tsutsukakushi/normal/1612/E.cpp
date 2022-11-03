/**
 *    author:  otera
 *    created: 22.11.2021 23:09:10 
**/
#include<bits/stdc++.h>
namespace otera{
    template<typename T>
    struct Rational {
        public:
            Rational() : Rational(0) {}
            Rational(T n) : num(n), den(1) {}
            Rational(T n, T d) {
                assert(d != 0);
                if(n == 0) num = 0, den = 1;
                else {
                    T g = std::gcd(n, d);
                    n /= g, d /= g;
                    if (d < 0) n = -n, d = -d;
                    num = n, den = d;
                }
            }

            T numerator() const { return num; }
            T denominator() const { return den; }

            int sgn() const {
                return -1 + (num >= 0) + (num > 0);
            }
            static int compare(const Rational &l, const Rational &r) {
                T g = std::abs(std::gcd(l.den, r.den));
                T val = r.den / g * l.num - l.den / g * r.num;
                return -1 + (val >= 0) + (val > 0);
            }

            friend bool operator<(const Rational &l, const Rational &r) {
                return compare(l, r) < 0;
            }
            friend bool operator>(const Rational &l, const Rational &r) {
                return compare(l, r) > 0;
            }
            friend bool operator<=(const Rational &l, const Rational &r) {
                return compare(l, r) <= 0;
            }
            friend bool operator>=(const Rational &l, const Rational &r) {
                return compare(l, r) >= 0;
            }
            friend bool operator==(const Rational &l, const Rational &r) {
                return compare(l, r) == 0;
            }
            friend bool operator!=(const Rational &l, const Rational &r) {
                return compare(l, r) != 0;
            }

            Rational operator+() const {
                return *this;
            }
            Rational operator-() const {
                return Rational(-num, den);
            }
            friend Rational operator+(const Rational &l, const Rational &r) {
                T lcm = l.den / std::gcd(l.den, r.den) * r.den;  
                lcm = std::abs(lcm);
                return Rational(l.num * (lcm / l.den) + r.num * (lcm / r.den), lcm);
            }
            friend Rational operator-(const Rational &l, const Rational &r) {
                T lcm = l.den / std::gcd(l.den, r.den) * r.den;
                lcm = std::abs(lcm);
                return Rational(l.num * (lcm / l.den) - r.num * (lcm / r.den), lcm);
            }
            friend Rational operator*(const Rational &l, const Rational &r) {
                T g1 = std::gcd(abs(l.num), abs(r.den));  g1 = std::abs(g1);
                T g2 = std::gcd(l.den, r.num);  g2 = std::abs(g2);
                return Rational((l.num / g1) * (r.num / g2), (l.den / g2) * (r.den / g1));
            }
            friend Rational operator/(const Rational &l, const Rational &r) {
                return l * r.inv();
            }
            Rational& operator+=(const Rational &r) {
                *this = *this + r;
                return *this;
            }
            Rational& operator-=(const Rational &r) {
                *this = *this - r;
                return *this;
            }
            Rational& operator*=(const Rational &r) {
                *this = *this * r;
                return *this;
            }
            Rational& operator/=(const Rational &r) {
                *this = *this / r;
                return *this;
            }
            Rational& operator++() {
                num += den;
                return *this;
            }
            Rational& operator--() {
                num -= den;
                return *this;
            }
            Rational inv() const {
                return Rational(den, num);
            }
            Rational abs() const {
                return Rational(std::abs(num), den);
            }

            explicit operator int() const {
                return (int)(num / den);
            }
            explicit operator long long() const {
                return (long long)(num / den);
            }
            explicit operator double() const {
                return (double)num / (double)den;
            }
            explicit operator long double() const {
                return (long double)num / (long double)den;
            }

            T floor() const {
                return num >= 0 ? num / den : -(-num / den);
            }
            T ceil() const {
                return num >= 0 ? -(-num / den) : num / den;
            }

            friend std::ostream &operator<<(std::ostream &os, const Rational &r) {
                return os << r.num << "/" << r.den;
            }

        private:
            T num, den;
    };
}

template <typename T>
otera::Rational<T> max(const otera::Rational<T> &l, const otera::Rational<T> &r) {
    return l > r ? l : r;
}
template <typename T>
otera::Rational<T> min(const otera::Rational<T> &l, const otera::Rational<T> &r) {
    return l < r ? l : r;
}
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

const int N = 200'200;
int cnt[N];

void solve() {
    rep(i, N) cnt[i] = 0;
    INT(n);
    vc<int> m(n), k(n);
    int ma = 0;
    rep(i, n) {
        in(m[i], k[i]);
        chmax(ma, k[i]);
    }
    otera::Rational<ll> ans(0);
    vc<int> c;
    rep1(i, 1, ma) {
        rep(j, n) {
            if(i <= k[j]) {
                cnt[m[j]] ++;
            }
        }
        ll sum = 0;
        pqg<P> now;
        debug(i);
        rep(j, N) {
            if(cnt[j] == 0) continue;
            now.push(P{cnt[j], j});
            sum += cnt[j];
            debug(j, cnt[j]);
            while(now.size() > i) {
                sum -= now.top().fr;
                now.pop();
            }
        }
        otera::Rational<ll> res(sum, i);
        debug(i, res);
        if(chmax(ans, res)) {
            ans = res;
            c.clear();
            while(now.size()) {
                c.eb(now.top().sc); now.pop();
            }
            dump(c);
        }
    }
    int t = si(c);
    out(t);
    out(c);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}