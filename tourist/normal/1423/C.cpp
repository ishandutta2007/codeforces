/**
 *    author:  tourist
 *    created: 05.10.2020 18:38:13       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<bool> alive(n, true);
  vector<int> sz(n);
  vector<int> pv(n);
  vector<pair<int, int>> ret;
  vector<int> all;
  vector<int> tin(n);
  vector<int> tout(n);
  int T = -1;
  function<void(int)> Dfs = [&](int v) {
    all.push_back(v);
    tin[v] = ++T;
    sz[v] = 1;
    for (int u : g[v]) {
      if (alive[u] && u != pv[v]) {
        pv[u] = v;
        Dfs(u);
        sz[v] += sz[u];
      }
    }
    tout[v] = ++T;
  };
  function<void(int)> Solve = [&](int v) {
    all.clear();
    pv[v] = -1;
    Dfs(v);
    int total = sz[v];
    while (true) {
      bool found = false;
      for (int u : g[v]) {
        if (alive[u] && pv[u] == v && 2 * sz[u] >= total) {
          v = u;
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    alive[v] = false;
    set<int> best;
    for (int u : g[v]) {
      if (alive[u]) {
        all.clear();
        pv[u] = -1;
        Dfs(u);
        set<int> cur;
        for (int w : g[u]) {
          if (alive[w]) {
            cur.insert(w);
          }
        }
        if (cur.size() > best.size()) {
          best = cur;
        }
      }
    }
    all.clear();
    pv[v] = -1;
    Dfs(v);
    for (int u : all) {
      if (u != v && pv[u] != v && best.find(u) == best.end()) {
        ret.emplace_back(u, v);
      }
    }
    vector<int> children;
    for (int u : g[v]) {
      if (alive[u]) {
        children.push_back(u);
      }
    }
    for (int u : children) {
      Solve(u);
    }
  };
  Solve(0);
  assert((int) ret.size() <= 10 * n);
//  ret.resize(min((int) ret.size(), 10 * n));
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}