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


/**
 * @brief Dinic()
 * @docs docs/dinic.md
 */
template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector< vector< edge > > graph;
  vector< int > min_cost, iter;

  explicit Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, cap, (int) graph[from].size() - 1, true, idx});
  }

  bool build_augment_path(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for(auto &e: graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t find_min_dist_augment_path(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    for(int &i = iter[idx]; i < (int) graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = find_min_dist_augment_path(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while(build_augment_path(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f;
      while((f = find_min_dist_augment_path(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e: graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }

  vector< bool > min_cut(int s) {
    vector< bool > used(graph.size());
    queue< int > que;
    que.emplace(s);
    used[s] = true;
    while(not que.empty()) {
      int p = que.front();
      que.pop();
      for(auto &e: graph[p]) {
        if(e.cap > 0 and not used[e.to]) {
          used[e.to] = true;
          que.emplace(e.to);
        }
      }
    }
    return used;
  }
};
/**
 * @brief Graph Template()
 */
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }

  inline vector< Edge< T > > &operator[](const int &k) {
    return g[k];
  }

  inline const vector< Edge< T > > &operator[](const int &k) const {
    return g[k];
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

/**
 * @brief Low Link(/)
 * @see http://kagamiz.hatenablog.com/entry/2013/10/05/005213
 * @docs docs/low-link.md
 */
template< typename T = int >
struct LowLink : Graph< T > {
public:
  using Graph< T >::Graph;
  vector< int > ord, low, articulation;
  vector< Edge< T > > bridge;
  using Graph< T >::g;

  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < (int) g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }

  explicit LowLink(const Graph< T > &g) : Graph< T >(g) {}

private:
  vector< int > used;

  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false, beet = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(to == par && !exchange(beet, true)) {
        continue;
      }
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= par >= 0 && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(to);
      } else {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }
};
int main(){
    LL(n,m,s,t);
    s--; t--;
    VEC(tuplis,edge,m);
    const ll lambda = 1LL << 40;
    Dinic<ll>g1(n);
    LowLink<ll>g(n);
    each(a,b,c,edge){
        a--; b--;
        g1.add_edge(a,b,c+lambda);
        g.add_edge(a,b);
    }
    g.build();
    vector<bool>is_bridge(m);
    each(e,g.bridge)is_bridge[e.idx]=1;
    Dinic<ll>g2(n);
    rep(m){
        auto[a,b,c]=edge[i];
        g2.add_edge(a,b,is_bridge[i]?LINF:c+lambda);
    }
    ll cost1=g1.max_flow(s,t);
    if(cost1==0){
        out(0);
        out(0);
        return 0;
    }
    if(cost1>>40>=3){
        out(-1);
        return 0;
    }
    auto cut1=g1.min_cut(s);
    pair<ll,vector<ll>>ans1;
    rep(m){
        auto[a,b,c]=edge[i];
        if(cut1[a]^cut1[b]){
            ans1.first+=c;
            ans1.second.push_back(i+1);
        }
    }
    assert(cost1>>40==ans1.second.size());
    ll cost2=g2.max_flow(s,t);
    if(cost2>>40==2){
        auto cut2=g2.min_cut(s);
        pair<ll,vector<ll>>ans2;
        rep(m){
            auto[a,b,c]=edge[i];
            if(cut2[a]^cut2[b]){
                ans2.first+=c;
                ans2.second.push_back(i+1);
            }
        }
        assert(ans2.second.size()==2);
        chmin(ans1,ans2);
    }
    out(ans1.first);
    out(ans1.second.size());
    out(ans1.second);
}