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
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
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
template <class T, class U> using umap = unordered_map<T, U>;
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

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_ {};

struct GabowEdmonds {

  struct edge {
    int to, idx;
  };

  vector< vector< edge > > g;
  vector< pair< int, int > > edges;
  vector< int > mate, label, first;
  queue< int > que;

  GabowEdmonds(int n) : g(n + 1), mate(n + 1), label(n + 1, -1), first(n + 1) {}

  void add_edge(int u, int v) {
    ++u, ++v;
    g[u].push_back((edge) {v, (int) (edges.size() + g.size())});
    g[v].push_back((edge) {u, (int) (edges.size() + g.size())});
    edges.emplace_back(u, v);
  }

  int find(int x) {
    if(label[first[x]] < 0) return first[x];
    first[x] = find(first[x]);
    return first[x];
  }

  void rematch(int v, int w) {
    int t = mate[v];
    mate[v] = w;
    if(mate[t] != v) return;
    if(label[v] < g.size()) {
      mate[t] = label[v];
      rematch(label[v], t);
    } else {
      int x = edges[label[v] - g.size()].first;
      int y = edges[label[v] - g.size()].second;
      rematch(x, y);
      rematch(y, x);
    }
  }

  void assign_label(int x, int y, int num) {
    int r = find(x);
    int s = find(y);
    int join = 0;
    if(r == s) return;
    label[r] = -num;
    label[s] = -num;
    while(true) {
      if(s != 0) swap(r, s);
      r = find(label[mate[r]]);
      if(label[r] == -num) {
        join = r;
        break;
      }
      label[r] = -num;
    }
    int v = first[x];
    while(v != join) {
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    v = first[y];
    while(v != join) {
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
  }

  bool augment_check(int u) {
    que = queue< int >();
    first[u] = 0;
    label[u] = 0;
    que.push(u);
    while(!que.empty()) {
      int x = que.front();
      que.pop();
      for(auto e : g[x]) {
        int y = e.to;
        if(mate[y] == 0 && y != u) {
          mate[y] = x;
          rematch(x, y);
          return true;
        } else if(label[y] >= 0) {
          assign_label(x, y, e.idx);
        } else if(label[mate[y]] < 0) {
          label[mate[y]] = x;
          first[mate[y]] = y;
          que.push(mate[y]);
        }
      }
    }
    return false;
  }

  vector< pair< int, int > > max_matching() {
    for(int i = 1; i < g.size(); i++) {
      if(mate[i] != 0) continue;
      if(augment_check(i)) label.assign(g.size(), -1);
    }
    vector< pair< int, int > > ret;
    for(int i = 1; i < g.size(); i++) {
      if(i < mate[i]) ret.emplace_back(i - 1, mate[i] - 1);
    }
    return ret;
  }
};

void solve() {
    INT(n, m);
    vvc<int> g(m + n * 2);
    GabowEdmonds gm(m + 2 * n);
    rep(j, n) {
        g[m + j].eb(m + n + j);
        g[m + n + j].eb(m + j);
        gm.add_edge(m + j, m + n + j);
    }
    rep(i, n) {
        rep(j, m) {
            CHR(c);
            if(c == '1') {
                g[m + i].eb(j);
                g[m + n + i].eb(j);
                g[j].eb(m + i);
                g[j].eb(m + n + i);
                gm.add_edge(j, m + i);
                gm.add_edge(j, m + n + i);
            }
        }
    }
    auto res = gm.max_matching();
    int ans = si(res) - n;
    out(ans);
}

signed main() {
    int testcase = 1;
    in(testcase);
    while(testcase--) solve();
    return 0;
}