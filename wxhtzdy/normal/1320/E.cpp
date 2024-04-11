#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  const int L = 25;
  vector<vector<int>> par(n, vector<int>(L));
  vector<int> tin(n), tout(n);
  vector<int> dep(n);
  int T = 0;
  function<void(int, int)> Dfs = [&](int u, int p) {
    tin[u] = ++T;
    par[u][0] = p;
    for (int j = 1; j < L; j++) {
      if (par[u][j - 1] != -1) {
        par[u][j] = par[par[u][j - 1]][j - 1];
      }
    }
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      dep[v] = dep[u] + 1;
      Dfs(v, u);
    }
    tout[u] = ++T;
  };
  Dfs(0, -1);
  auto anc = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };
  auto Lca = [&](int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int j = L - 1; j >= 0; j--) {
      if (par[u][j] != -1 && !anc(par[u][j], v)) {
        u = par[u][j];
      }
    }
    return par[u][0];
  };
  vector<vector<int>> e(n);
  vector<pair<int, int>> dist(n);
  int q;
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector<int> v(k), s(k);
    for (int i = 0; i < k; i++) {
      cin >> v[i] >> s[i];
      --v[i];
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> all;
    for (int i = 0; i < k; i++) {
      all.push_back(v[i]);
    }
    for (int i = 0; i < m; i++) {
      all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    sort(all.begin(), all.end(), [&](int i, int j) {
      return tin[i] < tin[j];
    });
    int sz = all.size();
    for (int i = 0; i + 1 < sz; i++) {
      all.push_back(Lca(all[i], all[i + 1]));
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    sort(all.begin(), all.end(), [&](int i, int j) {
      return tin[i] < tin[j];
    });
    for (int i = 0; i < all.size(); i++) {
      e[all[i]].clear();
    }
    vector<int> st;
    for (int i = 0; i < all.size(); i++) {
      while (st.size() > 0 && !anc(st.back(), all[i])) {
        st.pop_back();
      }
      if (st.size() > 0) {
        int x = st.back();
        int y = all[i];
        e[x].push_back(y);
        e[y].push_back(x);
      }
      st.push_back(all[i]);
    }
    for (int i = 0; i < all.size(); i++) {
      dist[all[i]] = {-1, -1};
    }
    set<tuple<int, int, int>> que;
    for (int i = 0; i < k; i++) {
      dist[v[i]] = {0, i};
      que.insert({0, i, v[i]});
    }
    auto Dist = [&](int x, int id) {
      int len = dep[x] + dep[v[id]] - 2 * dep[Lca(x, v[id])];
      return (len + s[id] - 1) / s[id];
    };
    while (!que.empty()) {
      auto it = que.begin();
      int x = get<2>(*it);
      int id = get<1>(*it);
      que.erase(it);
      for (int y : e[x]) {
        if (dist[y].first == -1 || dist[y] > make_pair(Dist(y, id), id)) {
          if (dist[y].first != -1) {
            que.erase(que.find({dist[y].first, dist[y].second, y}));
          }
          dist[y].first = Dist(y, id);
          dist[y].second = id;
          que.insert({dist[y].first, dist[y].second, y});
        }
      }
    }
    for (int i = 0; i < m; i++) {
      cout << dist[a[i]].second + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}