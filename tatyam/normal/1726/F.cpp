#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload5(a,b,c,d,e,name,...) name
#define overload4(a,b,c,d,name,...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each1(i,a) for(auto&&i:a)
#define each2(x,y,a) for(auto&&[x,y]:a)
#define each3(x,y,z,a) for(auto&&[x,y,z]:a)
#define each4(w,x,y,z,a) for(auto&&[w,x,y,z]:a)
#define each(...) overload5(__VA_ARGS__,each4,each3,each2,each1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) rbegin(i),rend(i)
#define rall2(i,a) rbegin(i),rbegin(i)+a
#define rall3(i,a,b) rbegin(i)+a,rbegin(i)+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),Modint{})
#define elif else if
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector name(h,vector(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T, class U> ll count(const T& a, const U& b){ return count(all(a), b); }
template<class T, class F> ll count_if(const T& a, F b){ return count_if(all(a), b); }
template<class T, class F> void filter(T& a, F b){ a.erase(remove_if(all(a), not_fn(b)), a.end()); }
template<class T, class F = less<>> void sor(T& a, F b = F{}){ sort(all(a), b); }
template<class T> void rev(T& a){ reverse(all(a)); }
template<class T> void uniq(T& a){ sor(a); a.erase(unique(all(a)), end(a)); }
ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a <= b) return 0; a = b; return 1; }
template<class T> bool chmax(T& a, const T& b){ if(a >= b) return 0; a = b; return 1; }
template<class T, class U> bool chmin(T& a, const U& b){ return chmin(a, T{b}); }
template<class T, class U> bool chmax(T& a, const U& b){ return chmax(a, T{b}); }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> auto run_press(const T& a){ vector<pair<decay_t<decltype(a[0])>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
template<class... Ts> void in(Ts&... t);
[[maybe_unused]] void print(){}
template<class T, class... Ts> void print(const T& t, const Ts&... ts);
template<class... Ts> void out(const Ts&... ts){ print(ts...); cout << '\n'; }
namespace IO{
#define VOID(a) decltype(void(a))
struct S{ S(){ cin.tie(nullptr)->sync_with_stdio(0); fixed(cout).precision(12); } }S;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){ in(get<idx>(t)...); }
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){ ituple(t, make_index_sequence<tuple_size<T>::value>{}); }
template<class T> void o(const T& t){ o(t, P<4>{}); }
template<size_t N> void o(const char (&t)[N], P<4>){ cout << t; }
template<class T, size_t N> void o(const T (&t)[N], P<3>){ o(t[0]); for(size_t i = 1; i < N; i++){ o(' '); o(t[i]); } }
template<class T> auto o(const T& t, P<2>) -> VOID(cout << t){ cout << t; }
template<class T> auto o(const T& t, P<1>) -> VOID(begin(t)){ bool first = 1; for(auto&& x : t) { if(first) first = 0; else o(' '); o(x); } }
template<class T, size_t... idx> void otuple(const T& t, index_sequence<idx...>){ print(get<idx>(t)...); }
template<class T> auto o(T& t, P<0>) -> VOID(tuple_size<T>{}){ otuple(t, make_index_sequence<tuple_size<T>::value>{}); }
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO::i(t)); }
template<class T, class... Ts> void print(const T& t, const Ts&... ts){ IO::o(t); unpack(IO::o((cout << ' ', ts))); }
#undef unpack
#ifdef DEBUG
ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
#define YESNO(yes,no) void yes(bool i = 1){ out(i?#yes:#no); } void no(){ out(#no); }
YESNO(first, second)
YESNO(First, Second)
YESNO(Yes, No)
YESNO(YES, NO)
YESNO(possible, impossible)
YESNO(POSSIBLE, IMPOSSIBLE)
void Case(ll i){ print("Case #"); print(i); print(": "); }



uint mod = MOD;
struct Modint{
    uint num = 0;
    Modint() noexcept {}
    Modint(const Modint &x) noexcept : num(x.num){}
    operator ll() const noexcept { return num; }
    Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    Modint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    Modint operator-() const noexcept { return Modint(0) -= *this; }
    Modint operator-(Modint x) const noexcept { return Modint(*this) -= x; }
    Modint& operator-=(Modint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    Modint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    Modint& operator*=(Modint x) noexcept { num = ull(num) * x.num % mod; return *this; }
    Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = uint(y);
    }
    template<class T> Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    Modint pow(ull x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::istream& operator>>(std::istream& is, Modint& x){ ll a; in(a); x = a; return is; }
Modint operator""_M(ull x) noexcept { return Modint(x); }
std::vector<Modint> fac(1, 1), inv(1, 1);
void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= mod) a = mod;
    while(fac.size() < a) fac.push_back(fac.back() * Modint(fac.size()));
    inv.resize(fac.size());
    inv.back() = fac.back().inv();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
Modint perm(ll n, ll r){
    if(r < 0 || n < r) return 0;
    if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
    reserve(n + 1); return fac[n] * inv[n - r];
}
Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; r = min(r, n - r); reserve(r + 1); return perm(n, r) * inv[r]; }
Modint Mcomb(ll n, ll r){ return comb(n + r - 1, r); } // rn
Modint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
void solve(){
    LL(n,t);
    mod=t;
    n--;
    VEC(pll,light,n+1);
    VEC(ll,d,n);
    d.insert(d.begin(),0);
    rep(n)d[i+1]+=d[i];
    map<ll,ll>dp;
    rep(n+1){
        auto&[g,c]=light[i];
        (c+=d[i])%=t;
        dp[Modint{-c}];
        dp[Modint{g-c}];
        dp[Modint{-c-1}];
        dp[Modint{g-c-1}];
    }
    ll ans=d[n];
    each(g,c,light){
        Modint s=-c,t=g-c;
        auto S=dp.try_emplace(s,LINF).first;
        auto p=dp.lower_bound(t);
        while(1){
            if(p==dp.end())p=dp.begin();
            if(p==S)break;
            auto[key,value]=*p;
            p=dp.erase(p);
            chmin(S->second,value+Modint{s-key});
        }
    }
    ll mn=LINF;
    each(key,value,dp)chmin(mn,value);
    out(ans+mn);
}
int main(){
    solve();
}