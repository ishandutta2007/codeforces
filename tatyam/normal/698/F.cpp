#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
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
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),Modint{0})
#define elif else if
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector name(h,vector(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T, class U> auto count(const T& a, const U& b){ return count(all(a), b); }
template<class T, class U> auto count_if(const T& a, U b){ return count_if(all(a), b); }
template<class T, class U> T filter(T a, U b){ a.erase(remove_if(all(a), not_fn(b)), a.end()); return a; }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> auto run_press(const T& a){ vector<pair<decay_t<decltype(a[0])>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
int in(){ return getchar(); }
void in(int& a){ scanf("%d", &a); }
void in(unsigned& a){ scanf("%u", &a); }
void in(long& a){ scanf("%ld", &a); }
void in(long long& a){ scanf("%lld", &a); }
void in(unsigned long long& a){ scanf("%llu", &a); }
void in(char& a){ do a = getchar(); while(a == ' ' || a == '\n'); }
void in(double& a){ scanf("%lf", &a); }
void in(long double& a){ scanf("%Lf", &a); }
void in(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; in(b); a[i] = b; } }
void in(char a[]){ scanf("%s", a); }
template<class T> void in(vector<T>&);
template<class T, size_t size> void in(array<T, size>&);
template<class T, class L> void in(pair<T, L>&);
template<class T, size_t size> void in(T(&)[size]);
template<class T> void in(vector<T>& a){ for(auto&& i : a) in(i); }
template<class T> void in(deque<T>& a){ for(auto&& i : a) in(i); }
template<class T, size_t size> void in(array<T, size>& a){ for(auto&& i : a) in(i); }
template<class T, class L> void in(pair<T, L>& p){ in(p.first); in(p.second); }
template<class T, size_t size> void in(T (&a)[size]){ for(auto&& i : a) in(i); }
template<class T> void in(T& a){ cin >> a; }
template <class... T> void in(T&... a){ (void)initializer_list<int>{ (in(a), 0)... }; }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char *a){ printf("%s", a); }
void print(const char *a){ printf("%s", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const complex<T>& a){ if(a.real() >= 0) print('+'); print(a.real()); if(a.imag() >= 0) print('+'); print(a.imag()); print('i'); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
int first(bool i = true){ return out(i?"first":"second"); }
int First(bool i = true){ return out(i?"First":"Second"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }



constexpr uint mod = MOD;
struct Modint{
    uint num = 0;
    constexpr Modint() noexcept {}
    constexpr Modint(const Modint &x) noexcept : num(x.num){}
    constexpr operator ll() const noexcept { return num; }
    constexpr Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    constexpr Modint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    constexpr Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    constexpr Modint operator-() const noexcept { return Modint(0) -= *this; }
    constexpr Modint& operator-=(Modint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    constexpr Modint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    constexpr Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    constexpr Modint& operator*=(Modint x) noexcept { num = ull(num) * x.num % mod; return *this; }
    constexpr Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = uint(y);
    }
    template<class T> constexpr Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> constexpr Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> constexpr Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> constexpr Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> constexpr Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> constexpr Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> constexpr Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> constexpr Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    constexpr Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    constexpr Modint pow(ull x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::istream& operator>>(std::istream& is, Modint& x){ ll a; in(a); x = a; return is; }
constexpr Modint operator""_M(ull x) noexcept { return Modint(x); }
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
Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(r + 1); return perm(n, r) * inv[r]; }
Modint Mcomb(ll n, ll r){ return comb(n + r - 1, r); } // r balls into n boxes
Modint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
vector<bool> sieve_of_atkin(int N){
    vector<bool> isprime(N + 1);
    const int sqrtN = sqrt(N);
    int n;
    for(int z = 1; z <= 5; z += 4) for(int y = z; y <= sqrtN; y += 6){
        for(int x = 1; x <= sqrtN && (n = 4*x*x+y*y) <= N; ++x) isprime[n] = !isprime[n];
        for(int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2) isprime[n] = !isprime[n];
    }
    for(int z = 2; z <= 4; z += 2) for(int y = z; y <= sqrtN; y += 6){
        for(int x = 1; x <= sqrtN && (n = 3*x*x+y*y) <= N; x += 2) isprime[n] = !isprime[n];
        for(int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2) isprime[n] = !isprime[n];
    }
    for(int y = 3; y <= sqrtN; y += 6) for(int z = 1; z <= 2; ++z){
        for(int x = z; x <= sqrtN && (n = 4*x*x+y*y) <= N; x += 3) isprime[n] = !isprime[n];
    }
    for(int n = 5; n <= sqrtN; ++n) if(isprime[n]) for(int k = n*n; k <= N; k+=n*n) isprime[k] = false;
    isprime[2] = isprime[3] = true;
    return isprime;
}
vector<int> primes(int N){
    auto isprime = sieve_of_atkin(N);
    vector<int> ans;
    for(int i = 2; i <= N; i++) if(isprime[i]) ans.push_back(i);
    return ans;
}
int main(){
    LL(n);
    auto prime=primes(n/2);
    VEC(ll,p,n);
    vec(vector<ll>,factor,n+1);
    vec(ll,square_free,n+1,1);
    each(p,prime)rep(i,p,n+1,p){
        factor[i].push_back(p);
        square_free[i]*=p;
    }
    unordered_map<ll,ll>cnt1,cnt2,f,revf;
    rep(i,1,n+1)cnt1[square_free[i]]++;
    each(p,prime)cnt2[n/p]++;
    auto mapping=[&](ll from,ll to){
        if(n/from!=n/to)exit(out(0));
        {
            auto[p,flag]=f.try_emplace(from,to);
            if(p->second!=to)exit(out(0));
        }
        auto[p,flag]=revf.try_emplace(to,from);
        if(p->second!=from)exit(out(0));
        if(from*2<=n&&flag)cnt2[n/from]--;
    };
    p.insert(p.begin(),0);
    rep(i,1,n+1)if(p[i]){
        const auto&fac1=factor[i],&fac2=factor[p[i]];
        if(fac1.size()!=fac2.size())exit(out(0));
        rep(fac1.size())mapping(fac1[i],fac2[i]);
        cnt1[square_free[p[i]]]--;
    }
    Modint ans=1;
    each(key,val,cnt1)ans*=fact(val);
    each(key,val,cnt2)ans*=fact(val);
    out(ans);
}