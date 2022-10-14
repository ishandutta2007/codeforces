/**
 *    author: m371
 *    created: 07.10.2021 12:28:27
**/
#include <bits/stdc++.h>

using namespace std;

class matching {
  public:
  vector< vector<int> > g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;
  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was = vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }
  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }
  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }
  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }
  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e;
  for (int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    --u; --v;
    e.emplace_back(d, u, v);
  }
  sort(e.begin(), e.end());
  int bot = n - 1, top = m, ans = -1;
  while (bot <= top) {
    int mid = bot + top >> 1;
    matching mc(n, n);
    for (int i = 0; i < m; i++) {
      if (get<0>(e[i]) <= get<0>(e[mid])) {
        mc.add(get<1>(e[i]), get<2>(e[i]));
      }  
    }
    if (mc.solve() == n) {
      ans = get<0>(e[mid]);
      top = mid - 1;
    } else {
      bot = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}