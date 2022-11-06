#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int s, t;
  cin >> s >> t;
  s--, t--;
  vector<int> x(m), y(m), w(m);
  vector<int> ed;
  vector<int> uf(n);
  iota(uf.begin(), uf.end(), 0);

  function<int(int)> Find = [&](int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
  };

  auto Merge = [&](int x, int y) {
    uf[Find(x)] = Find(y);
  };

  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i] >> w[i];
    x[i]--, y[i]--;
    ed.push_back(i);
    Merge(x[i], y[i]);
  }
  if (Find(s) != Find(t)) {
    cout << "0\n";
    cout << "0\n";
    return 0;
  }
  constexpr int kIter = 5;
  vector<int> use;
  sort(ed.begin(), ed.end(), [&](int i, int j) { return w[i] < w[j]; });
  for (int it = 0; it < kIter; ++it) {
    iota(uf.begin(), uf.end(), 0);
    vector<int> ned;

    for (int i = 0; i < ed.size(); ++i) {
      if (Find(x[ed[i]]) == Find(y[ed[i]])) {
        ned.push_back(ed[i]);
      } else {
        Merge(x[ed[i]], y[ed[i]]);
        use.push_back(ed[i]);
      }
    }
    ed = ned;
  }

  vector<int> dfn(n, -1), low(n), bcc(n);
  vector<int> bridge, stk;
  int tk = 0, nbcc = 0;
  vector<vector<int>> g(n);

  function<void(int, int, int, int)> Dfs = [&](int v, int p, int fb, int fe) {
    low[v] = dfn[v] = tk++;
    stk.push_back(v);
    for (int e : g[v]) {
      if (e == fb) continue;
      if (e == p) continue;
      int u = x[e] ^ y[e] ^ v;
      if (dfn[u] >= 0) {
        low[v] = min(low[v], dfn[u]);
      } else {
        Dfs(u, e, fb, e);
        low[v] = min(low[v], low[u]);
      }
    }
    if (low[v] == dfn[v]) {
      while (true) {
        int u = stk.back();
        stk.pop_back();
        bcc[u] = nbcc;
        if (u == v) break;
      }
      nbcc++;
      if (fe >= 0) bridge.push_back(fe);
    }
  };

  int ans = 2'000'000'000 + 1;
  int e1 = -1, e2 = -1;

  {
    for (int i = 0; i < m; ++i) {
      g[x[i]].push_back(i);
      g[y[i]].push_back(i);
    }
    Dfs(0, -1, -1, -1);
    if (bcc[s] != bcc[t]) {
      vector<vector<pair<int, int>>> gd(nbcc);
      for (int e : bridge) {
        if (bcc[x[e]] == bcc[y[e]]) while (true);
        gd[bcc[x[e]]].emplace_back(bcc[y[e]], e);
        gd[bcc[y[e]]].emplace_back(bcc[x[e]], e);
      }

      function<int(int, int)> Dfs2 = [&](int x, int p) {
        int res = x == bcc[t];
        for (auto &e : gd[x]) {
          int u = e.first;
          if (u == p) continue;
          if (Dfs2(u, x)) {
            res = 1;
            if (w[e.second] < ans) {
              ans = w[e.second];
              e1 = e.second;
              e2 = -1;
            }
          }
        }
        return res;
      };

      Dfs2(bcc[s], -1);
    }
  }

  for (int i = 0; i < n; ++i) g[i].clear();
  for (int i = 0; i < use.size(); ++i) {
    g[x[use[i]]].push_back(use[i]);
    g[y[use[i]]].push_back(use[i]);
  }

  for (int i = 0; i < use.size(); ++i) {
    fill(dfn.begin(), dfn.end(), -1);
    tk = 0;
    bridge.clear();
    nbcc = 0;
    Dfs(t, -1, use[i], -1);
    if (dfn[s] == -1) continue;
    if (bcc[s] == bcc[t]) continue;
    vector<vector<pair<int, int>>> gd(nbcc);
    for (int e : bridge) {
      if (bcc[x[e]] == bcc[y[e]]) while (true);
      // assert(bcc[x[e]] != bcc[y[e]]);
      gd[bcc[x[e]]].emplace_back(bcc[y[e]], e);
      gd[bcc[y[e]]].emplace_back(bcc[x[e]], e);
    }

    function<int(int, int)> Dfs2 = [&](int x, int p) {
      int res = x == bcc[t];
      for (auto &e : gd[x]) {
        int u = e.first;
        if (u == p) continue;
        if (Dfs2(u, x)) {
          res = 1;
          if (w[use[i]] + w[e.second] < ans) {
            ans = w[use[i]] + w[e.second];
            e1 = use[i];
            e2 = e.second;
          }
        }
      }
      return res;
    };

    Dfs2(bcc[s], -1);
  }
  if (ans == 2'000'000'001) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << "\n";
  int cnt = (e1 != -1) + (e2 != -1);
  cout << cnt << "\n";
  cout << e1 + 1;
  if (e2 != -1) cout << " " << e2 + 1;
  cout << "\n";
}