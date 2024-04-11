#pragma GCC optimize("fast-math")
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
template<class... Ts> void in(Ts&... t);
[[maybe_unused]] void print(){}
template<class T, class... Ts> void print(const T& t, const Ts&... ts);
template<class... Ts> void out(const Ts&... ts){ print(ts...); cout << '\n'; }
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{
    setting(){
        cin.tie(nullptr); ios::sync_with_stdio(false);
        fixed(cout); cout.precision(12);
    }
} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);
}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});
}
template<class T> void o(const T& t){ o(t, P<4>{}); }
template<size_t N> void o(const char (&t)[N], P<4>){ cout << t; }
template<class T, size_t N> void o(const T (&t)[N], P<3>){
    o(t[0]); for(size_t i = 1; i < N; i++){ o(' '); o(t[i]); }
}
template<class T> auto o(const T& t, P<2>) -> VOID(cout << t){ cout << t; }
template<class T> auto o(const T& t, P<1>) -> VOID(begin(t)){ bool first = 1; for(auto&& x : t) { if(first) first = 0; else o(' '); o(x); } }
template<class T, size_t... idx> void otuple(const T& t, index_sequence<idx...>){
    print(get<idx>(t)...);
}
template<class T> auto o(T& t, P<0>) -> VOID(tuple_size<T>{}){
    otuple(t, make_index_sequence<tuple_size<T>::value>{});
}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO::i(t)); }
template<class T, class... Ts> void print(const T& t, const Ts&... ts){
    IO::o(t); unpack(IO::o((cout << ' ', ts)));
}
#undef unpack
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
void first(bool i = true){ return out(i?"first":"second"); }
void First(bool i = true){ return out(i?"First":"Second"); }
void Yes(bool i = true){ return out(i?"Yes":"No"); }
void No(){ return out("No"); }
void YES(bool i = true){ return out(i?"YES":"NO"); }
void NO(){ return out("NO"); }
void Yay(bool i = true){ return out(i?"Yay!":":("); }
void possible(bool i = true){ return out(i?"possible":"impossible"); }
void Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
void POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }



template<class T>
struct Matrix{
    size_t N, M;
    vector<T> a;
    Matrix(size_t N, size_t M): N(N), M(M), a(N * M, LINF){}
    Matrix(const vector<vector<T>>& b): Matrix(b.size(), b[0].size()){
        for(size_t i = 0; i < N; i++) for(size_t j = 0; j < M; j++) *this[i][j] = b[i][j];
    }
    static Matrix e(size_t N){
        Matrix a(N, N);
        for(size_t i = 0; i < N; i++) a[i][i] = T{0};
        return a;
    }
    auto operator[](size_t i){ return a.begin() + i * M; }
    auto operator[](size_t i) const { return a.begin() + i * M; }
    Matrix operator*(const Matrix& b) const {
        assert(M == b.N);
        const size_t K = b.M;
        Matrix c(N, K);
        for(size_t i = 0; i < N; i++) for(size_t j = 0; j < M; j++) for(size_t k = 0; k < K; k++) chmin(c[i][k], (*this)[i][j] + b[j][k]);
        return c;
    }
    Matrix& operator*=(const Matrix& b){
        return *this = Matrix(*this) * b;
    }
    Matrix pow(long long r) const {
        if(r == 0) return e(N);
        Matrix ans = e(N), A = *this;
        while(1){
            if(r & 1) ans *= A;
            if(r == 1) return ans;
            A *= A;
            r >>= 1;
        }
    }
};
int main(){
    /*
      k - 1 ( k )
     k = 8, x = 4  binom(8, 4) = 70
     
     O(q * (binom(k, x))^3 * log(n)) ~ 2.3e8
      2 
     O(q * (binom(k, x))^2 * log(n) + (binom(k, x))^3 * log(n)) ~ 1.2e7
     */
    LL(x,k,n,q);
    VEC(ll,c,k);
    vector<ll>bits,idx(1<<k,-1);
    rep(bit,1<<k)if(popcnt(bit)==x){
        idx[bit]=bits.size();
        bits.push_back(bit);
    }
    VEC(pll,land,q);
    each(i,c,land)i--;
    Sort(land);
    ll ans=0;
    while(land.size()&&land.back().first>=n-x){
        ans+=land.back().second;
        land.pop_back();
    }
    land.emplace_back(n-x,0);
    const ll siz=bits.size();
    Matrix<ll> A(siz,siz);
    rep(siz){
        const ll bit=bits[i];
        const ll bit2=bit>>1;
        if(!(bit&1)){
            A[i][idx[bit2]]=0;
            continue;
        }
        rep(j,k)if(!(bit2&1<<j)){
            A[i][idx[bit2|1<<j]]=c[j];
        }
    }
    vector<Matrix<ll>>powA={A};
    rep(26)powA.push_back(powA[i]*powA[i]);
    Matrix<ll> v(1,siz);
    v[0][0]=ans;
    ll at=0;
    each(nxt,c,land){
        const ll d=nxt-at;
        at=nxt;
        rep(l,27)if(d&1<<l)v*=powA[l];
        rep(siz)if(bits[i]&1)v[0][i]+=c;
        if(nxt==n-x){
            out(v[0][0]);
            return 0;
        }
    }
}