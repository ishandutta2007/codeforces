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
#define Msum(...) accumulate(all(__VA_ARGS__),0_M)
#define elif else if
#define unless(a) if(!(a))
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
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T, class U> auto count(const T& a, const U& b){ return count(all(a), b); }
template<class T, class U> auto count_if(const T& a, U b){ return count_if(all(a), b); }
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
template<class T> auto run_press(const T& a){ vector<pair<remove_const_t<remove_reference_t<decltype(a[0])>>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do a = getchar(); while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class... T> void in(T&... a){ (void)initializer_list<int>{ (scan(a), 0)... }; }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
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
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }




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
Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(r + 1); return perm(n, r) * inv[r]; }
Modint Mcomb(ll n, ll r){ return comb(n + r - 1, r); } // rn
Modint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
struct WeightedEdge{
    ll to;
    Modint cost;
    WeightedEdge(){}
    WeightedEdge(ll to, Modint cost): to(to), cost(cost){}
    operator ll() const { return to; }
};
struct WeightedGraph{
    using E = WeightedEdge;
    vector<vector<E>> g;
    WeightedGraph(){}
    WeightedGraph(ll n): g(n){}
    vector<E>& operator[](ll at){ return g[at]; }
    operator vector<vector<E>>&(){ return g; }
    auto begin(){ return g.begin(); }
    auto end(){ return g.end(); }
    auto begin() const { return g.cbegin(); }
    auto end() const { return g.cend(); }
    ll size() const { return g.size(); }
    void resize(ll n){ g.resize(n); }
    const vector<E>& operator[](ll at) const { return g[at]; }
    operator const vector<vector<E>>&() const { return g; }
    void add_edge(ll a, ll b, ll cost){
        g[a].emplace_back(b, cost);
        g[b].emplace_back(a, cost);
    }
    void add_directed_edge(ll from, ll to, ll cost){
        g[from].emplace_back(to, cost);
    }
    template<ll start_index = 1> void input_graph(ll m){
        while(m--){
            ll a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }
    }
    template<ll start_index = 1> void input_directed_graph(ll m){
        while(m--){
            ll a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b, c);
        }
    }
    template<ll start_index = 1> void input_tree(ll n = -1){ if(n == -1) n = g.size(); input_graph<start_index>(n - 1); }
};
struct UnWeightedEdge{
    ll to;
    static constexpr ll cost = 1;
    UnWeightedEdge(){}
    UnWeightedEdge(ll to): to(to){}
    operator ll() const { return to; }
};
struct UnWeightedGraph{
    using E = UnWeightedEdge;
    vector<vector<E>> g;
    UnWeightedGraph(){}
    UnWeightedGraph(ll n): g(n){}
    vector<E>& operator[](ll at){ return g[at]; }
    operator vector<vector<E>>&(){ return g; }
    auto begin(){ return g.begin(); }
    auto end(){ return g.end(); }
    auto begin() const { return g.cbegin(); }
    auto end() const { return g.cend(); }
    ll size() const { return g.size(); }
    void resize(ll n){ g.resize(n); }
    const vector<E>& operator[](ll at) const { return g[at]; }
    operator const vector<vector<E>>&() const { return g; }
    void add_edge(ll a, ll b){
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    void add_directed_edge(ll from, ll to){
        g[from].emplace_back(to);
    }
    template<ll start_index = 1> void input_graph(ll m){
        while(m--){
            ll a, b;
            scanf("%lld%lld", &a, &b);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }
    template<ll start_index = 1> void input_directed_graph(ll m){
        while(m--){
            ll a, b;
            scanf("%lld%lld", &a, &b);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b);
        }
    }
    template<ll start_index = 1> void input_tree(ll n = -1){ if(n == -1) n = g.size(); input_graph<start_index>(n - 1); }
};
template< typename G >
struct CentroidDecomposition {
  const G &g;
  vector< int > sub;
  vector< vector< int > > belong;
  vector< bool > v;

  CentroidDecomposition(const G &g) : g(g), sub(g.size()), v(g.size()), belong(g.size()) {}

  inline int build_dfs(int idx, int par) {
    sub[idx] = 1;
    for(auto &to : g[idx]) {
      if(to == par || v[to]) continue;
      sub[idx] += build_dfs(to, idx);
    }
    return sub[idx];
  }

  inline int search_centroid(int idx, int par, const int mid) {
    for(auto &to : g[idx]) {
      if(to == par || v[to]) continue;
      if(sub[to] > mid) return search_centroid(to, idx, mid);
    }
    return idx;
  }

  inline void belong_dfs(int idx, int par, int centroid) {
    belong[idx].emplace_back(centroid);
    for(auto &to : g[idx]) {
      if(to == par || v[to]) continue;
      belong_dfs(to, idx, centroid);
    }
  }

  inline int build(UnWeightedGraph &t, int idx) {
    int centroid = search_centroid(idx, -1, build_dfs(idx, -1) / 2);
    v[centroid] = true;
    belong_dfs(centroid, -1, centroid);
    for(auto &to : g[centroid]) {
      if(!v[to]) t[centroid].emplace_back(build(t, to));
    }
    v[centroid] = false;
    return centroid;
  }

  inline int build(UnWeightedGraph &t) {
    t.resize(g.size());
    return build(t, 0);
  }
};
int main(){
    LL(n);
    in(mod);
    WeightedGraph g(n);
    g.input_tree<0>();
    UnWeightedGraph G;
    const ll cen=[&]{
        CentroidDecomposition cen(g);
        return cen.build(G);
    }();
    vec(bool,used,n);
    ll ans=0;
    const Modint m10=10_M,inv10=m10.inv();
    auto solve=[&](ll at){
        vector<pair<vector<Modint>,vector<Modint>>>s;
        each(i,g[at]){
            vector<Modint>a,b;
            auto dfs = [&](ll from, ll at, Modint s1, Modint w1, Modint s2, Modint w2, auto dfs) -> void {
                a.push_back(s1);
                b.push_back(s2);
                if(used[at])return;
                each(i,g[at])if(i!=from)dfs(at,i,s1+w1*i.cost,w1*m10,s2+w2*i.cost,w2*inv10,dfs);
            };
            dfs(at,i,i.cost,m10,i.cost*inv10,inv10*inv10,dfs);
            s.emplace_back(move(a),move(b));
        }
        unordered_map<uint,uint>cnt;
        each(a,b,s)each(x,a)cnt[x]++;
        each(a,b,s){
            each(x,a)cnt[x]--;
            each(x,b)ans+=cnt[-x];
            each(x,a)cnt[x]++;
        }
    };
    auto dfs = [&](ll from, ll at, auto dfs) -> void {
        solve(at);
        used[at] = 1;
        each(i, G[at]) if(i != from){
            dfs(at, i, dfs);
        }
    };
    dfs(-1, cen, dfs);
    rep(n)each(j,g[i])if(j.cost==0)ans++;
    out(ans);
}