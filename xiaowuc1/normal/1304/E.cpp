#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(0) cerr
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

struct LCA {
  vector<vector<int>> edges;
  vector<vector<int>> anc;
  vector<int> depth;
  int D;
  LCA(int n) {
    edges.resize(n);
    depth.resize(n); fill(all(depth), -1);
    anc.resize(n);
    D = 1;
    while((1<<D) <= n) D++;
    for(int i = 0; i < n; i++) anc[i].resize(D);
    for(int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      edges[a].pb(b);
      edges[b].pb(a);
    }
  }
  int getParent(int x) {
    return anc[x][0];
  }
  int getDepth(int x) {
    return depth[x];
  }
  int getAncestor(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int i = D-1; i >= 0; i--) {
      if(depth[a] - depth[b] >= (1<<i)) a = anc[a][i];
    }
    assert(depth[a] == depth[b]);
    for(int i = D-1; i >= 0; i--) {
      if(anc[a][i] != anc[b][i]) {
        a = anc[a][i];
        b = anc[b][i];
      }
    }
    if(a != b) return anc[a][0];
    return a;
  }
  void init() {
    auto dfs = y_combinator([&](auto self, int curr) -> void {
      for(int out: edges[curr]) {
        if(depth[out] >= 0) continue;
        depth[out] = depth[curr]+1;
        anc[out][0] = curr;
        self(out);
      }
    });
    depth[0] = 0;
    dfs(0);
    for(int d = 1; d < D; d++) for(int i = 0; i < sz(depth); i++) anc[i][d] = anc[anc[i][d-1]][d-1];
  }
};

void solve() {
  int n;
  cin >> n;
  LCA lca(n);
  lca.init();
  int q;
  cin >> q;
  while(q--) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    x--; y--;
    a--; b--;
    bool can = false;
    int d;
    d = lca.getDepth(a) + lca.getDepth(b) - 2 * lca.getDepth(lca.getAncestor(a, b));
    if(d%2 == k%2 && d <= k) can = true;
    d = lca.getDepth(a) + lca.getDepth(x) - 2 * lca.getDepth(lca.getAncestor(a, x)) + 1 + lca.getDepth(b) + lca.getDepth(y) - 2 * lca.getDepth(lca.getAncestor(b, y));
    if(d%2 == k%2 && d <= k) can = true;
    d = lca.getDepth(a) + lca.getDepth(y) - 2 * lca.getDepth(lca.getAncestor(a, y)) + 1 + lca.getDepth(b) + lca.getDepth(x) - 2 * lca.getDepth(lca.getAncestor(b, x));
    if(d%2 == k%2 && d <= k) can = true;
    if(can) cout << "YES\n";
    else cout << "NO\n";
  }
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}