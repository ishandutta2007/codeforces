#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dfn(n, -1), dep(n);
  vector<vector<int>> fa(n);
  function<void(int, int)> Dfs = [&](int x, int p) {
    static int tk = 0;
    dfn[x] = tk++;
    dep[x] = ~p ? dep[p] + 1 : 0;
    fa[x].push_back(p);
    for (int i = 1; (1 << i) <= dep[x]; ++i) fa[x].push_back(fa[fa[x][i - 1]][i - 1]);
    for (int u : g[x]) {
      if (u == p) continue;
      Dfs(u, x);
    }
  };

  auto GetLCA = [&](int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 0; i < fa[v].size(); ++i) {
      if ((dep[v] - dep[u]) >> i & 1) v = fa[v][i];
    }
    if (u == v) return u;
    for (int i = min(fa[u].size(), fa[v].size()) - 1; i >= 0; --i) {
      if (i < fa[u].size() && i < fa[v].size() && fa[u][i] != fa[v][i]) {
        u = fa[u][i];
        v = fa[v][i];
      }
    }
    return fa[u][0];
  };

  vector<vector<pair<int, int>>> virt(n);
  vector<int> used;

  auto Dist = [&](int u, int v) {
    return dep[u] + dep[v] - 2 * dep[GetLCA(u, v)];
  };

  auto BuildVirtualTree = [&](vector<int> v) {
    static vector<int> stk(n);
    int sz = 0;
    sort(v.begin(), v.end(), [&](int i, int j) { return dfn[i] < dfn[j]; });
    stk[sz++] = 0;

    for (int u : v) used.push_back(u);

    auto AddEdge = [&](int u, int v) {
      virt[u].emplace_back(v, Dist(u, v));
      virt[v].emplace_back(u, Dist(u, v));
      used.push_back(u);
      used.push_back(v);
    };

    for (int u : v) {
      if (u == 0) continue;
      int p = GetLCA(u, stk[sz - 1]);
      if (p != stk[sz - 1]) {
        while (sz >= 2 && dfn[p] < dfn[stk[sz - 2]]) {
          AddEdge(stk[sz - 2], stk[sz - 1]);
          --sz;
        }
        if (sz >= 2 && dfn[p] > dfn[stk[sz - 2]]) {
          AddEdge(p, stk[sz - 1]);
          stk[sz - 1] = p;
        } else {
          AddEdge(p, stk[--sz]);
        }
      }
      stk[sz++] = u;
    }
    for (int i = 0; i < sz - 1; ++i) AddEdge(stk[i], stk[i + 1]);
  };

  vector<int> spr(n, -1), wh(n, -1), ans(n, -1);
  vector<int> virus(n, -1), dist(n, -1), dp(n, -1), spd(n, -1);
  vector<bool> target(n);
  vector<multiset<tuple<int, int, int, int>>> st(n);

  auto Recover = [&]() {
    for (int u : used) {
      virt[u].clear();
      spr[u] = -1;
      target[u] = false;
      wh[u] = -1;
      virus[u] = -1;
      dist[u] = -1;
      dp[u] = -1;
      spd[u] = -1;
      st[u].clear();
    }
    used.clear();
  };


  auto Solve = [&]() {
    function<void(int, int)> Dfs2 = [&](int x, int p) {
      for (auto e : virt[x]) {
        int u = e.first, w = e.second;
        if (u == p) continue;
        Dfs2(u, x);
        if (virus[u] == -1) continue;
        int ndp = -1, ndist = -1;
        if (dist[u] >= w) {
          ndp = dp[u];
          ndist = dist[u] - w;
        } else {
          int rem = w - dist[u];
          ndp = dp[u] + (rem + spd[u] - 1) / spd[u];
          ndist = spd[u] * ((rem + spd[u] - 1) / spd[u]) - rem;
        }
        st[x].insert(make_tuple(ndp, virus[u], ndist, spd[u]));
      }
      if (spr[x] != -1) st[x].insert(make_tuple(0, wh[x], 0, spr[x]));
      if (!st[x].empty()) {
        dp[x] = get<0>(*st[x].begin());
        virus[x] = get<1>(*st[x].begin());
        dist[x] = get<2>(*st[x].begin());
        spd[x] = get<3>(*st[x].begin());
      }
    };

    function<void(int, int, tuple<int, int, int, int>)> Dfs3 = [&](int x, int p, tuple<int, int, int, int> f) {
      if (get<0>(f) != -1) st[x].insert(f);
      // cout << "Dfs3 x = " << x << " f = " << get<0>(f) << " " << get<1>(f) << " " << get<2>(f) << " " << get<3>(f) << endl;
      assert(!st[x].empty());
      ans[x] = get<1>(*st[x].begin());
      for (auto e : virt[x]) {
        int u = e.first, w = e.second;
        // cout << "x = " << x << " u = " << u << " w = " << w << endl;
        if (u == p) continue;
        tuple<int, int, int, int> c{-1, -1, -1, -1};
        if (virus[u] != -1) {
          int ndp = -1, ndist = -1;
          if (dist[u] >= w) {
            ndp = dp[u];
            ndist = dist[u] - w;
          } else {
            int rem = w - dist[u];
            ndp = dp[u] + (rem + spd[u] - 1) / spd[u];
            ndist = spd[u] * ((rem + spd[u] - 1) / spd[u]) - rem;
          }
          c = make_tuple(ndp, virus[u], ndist, spd[u]);
        }
        if (get<0>(c) != -1) st[x].erase(st[x].find(c));
        
        if (st[x].empty()) {
          Dfs3(u, x, make_tuple(-1, -1, -1, -1));
        } else {
          auto ff = *st[x].begin();
          // cout << "ff = " << get<0>(ff) << " " << get<1>(ff) << " " << get<2>(ff) << " " << get<3>(ff) << endl;
          int ndp = -1, ndist = -1;
          if (get<2>(ff) >= w) {
            ndp = get<0>(ff);
            ndist = get<2>(ff) - w;
          } else {
            int rem = w - get<2>(ff);
            ndp = get<0>(ff) + (rem + get<3>(ff) - 1) / get<3>(ff);
            ndist = get<3>(ff) * ((rem + get<3>(ff) - 1) / get<3>(ff)) - rem;
          }
          ff = make_tuple(ndp, get<1>(ff), ndist, get<3>(ff));
          Dfs3(u, x, ff);
        }
        if (get<0>(c) != -1) st[x].insert(c);
      }
    };

    Dfs2(0, -1);
    // for (int u : used) {
      // cout << "u = " << u << " virus = " << virus[u] << " dp = " << dp[u] << " dist = " << dist[u] << endl;
    // }
    Dfs3(0, -1, make_tuple(-1, -1, -1, -1));
  };

  Dfs(0, -1);
  int q;
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector<int> v(k), s(k), u(m), uniq;
    for (int i = 0; i < k; ++i) {
      cin >> v[i] >> s[i];
      v[i]--;
      uniq.push_back(v[i]);
      spr[v[i]] = s[i];
      wh[v[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
      cin >> u[i];
      u[i]--;
      target[u[i]] = true;
      uniq.push_back(u[i]);
    }
    sort(uniq.begin(), uniq.end());
    uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());
    BuildVirtualTree(uniq);
    Solve();
    Recover();
    for (int i : u) cout << ans[i] + 1 << ' ';
    cout << "\n";
  }
  return 0;
}