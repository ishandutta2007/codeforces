#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 2e5 + 5;
  vector<bool> pr(MAX, true);
  pr[0] = pr[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (!pr[i]) {
      continue;
    }
    for (int j = i + i; j < MAX; j += i) {
      pr[j] = false;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> edges(MAX);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int w = __gcd(a[x], a[y]);
    for (int d = 1; d * d <= w; d++) {
      if (w % d != 0) {
        continue;
      }
      if (pr[d]) {
        edges[d].emplace_back(x, y);
      }
      if (d != w / d && pr[w / d]) {
        edges[w / d].emplace_back(x, y);
      }
    }
  }
  vector<vector<int>> g(n);
  vector<bool> was(n, false);
  vector<int> dep(n);
  int ans = (*max_element(a.begin(), a.end()) > 1 ? 1 : 0);
  for (int i = 2; i < MAX; i++) {
    vector<int> nodes;
    for (auto ed : edges[i]) {
      nodes.push_back(ed.first);
      nodes.push_back(ed.second);
    }
    for (int id : nodes) {
      g[id].clear();
      was[id] = false;
    }
    for (auto ed : edges[i]) {
      g[ed.first].push_back(ed.second);
      g[ed.second].push_back(ed.first);
    }
    vector<int> comp;
    function<void(int)> Dfs1 = [&](int u) {
      was[u] = true;
      comp.push_back(u);
      for (int v : g[u]) {
        if (!was[v]) {
          Dfs1(v);
        }
      }
    };
    function<void(int, int)> Dfs2 = [&](int u, int d) {
      dep[u] = d;
      was[u] = true;
      for (int v : g[u]) {
        if (!was[v]) {
          Dfs2(v, d + 1);
        }
      }
    };
    for (int id : nodes) {
      if (was[id]) {
        continue;
      }
      comp.clear();
      Dfs1(id);
      for (int p : comp) {
        was[p] = false;
      }
      Dfs2(id, 1);
      for (int p : comp) {
        was[p] = false;
      }
      int c1 = id;
      for (int p : comp) {
        if (dep[p] > dep[c1]) {
          c1 = p;
        }
      }
      Dfs2(c1, 1);
      for (int p : comp) {
        was[p] = true;
        ans = max(ans, dep[p]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}