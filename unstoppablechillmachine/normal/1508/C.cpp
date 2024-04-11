#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    sz.resize(n + 1, 1);
    p.resize(n + 1);
    iota(all(p), 0);
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return false;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    sz[a] += sz[b];
    p[b] = a;
    return true;
  }
};

const ll INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> edges, interesting;
  set<pair<int, int>> used;
  int val = 0;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    if (u > v) {
      swap(u, v);
    }
    used.insert({u, v});
    used.insert({v, u});
    edges.pb({c, {u, v}});
    val ^= c;
  }
  sort(all(edges));
  DSU G(n);
  for (auto it : edges) {
    if (G.merge(it.S.F, it.S.S)) {
      interesting.pb(it);
    }
  }

  set<int> unused;
  for (int i = 1; i <= n; i++) {
    unused.insert(i);
  }  
  int cnt = 0;
  
  function<void(int)> dfs = [&](int v) {
    int lst = 0;
    while (!unused.empty()) {
      auto it = unused.upper_bound(lst);
      if (it == unused.end()) {
        break;
      }
      lst = *it;
      if (!used.count({lst, v})) {
        cnt++;
        interesting.pb({0ll, {v, lst}});
        unused.erase(lst);
        dfs(lst);
      }
    }
  };

  while (!unused.empty()) {
    int v = *unused.begin();
    unused.erase(unused.begin());
    dfs(v);
  }
  reverse(all(interesting));
  
  auto mst = [](int n, vector<pair<int, pair<int, int>>> edges) {
    sort(all(edges));
    DSU G(n);
    int ans = 0;
    for (auto it : edges) {
      if (G.merge(it.S.F, it.S.S)) {
        ans += it.F;
      }
    }
    return ans;
  };

  if (m + cnt == n * (n - 1) / 2) {
    int ans = INF;
    for (int i = 0; i < cnt; i++) {
      interesting[i].F = val;
      ans = min(ans, mst(n, interesting));
      interesting[i].F = 0;
    }
    cout << ans << '\n';
  }
  else {
    cout << mst(n, interesting) << '\n';
  }
}