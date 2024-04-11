#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> e(N);
  for (int i = 0; i < N; ++i) {
    cin >> e[i];
  }
  vector<vector<pair<int, int>>> g(N);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N - 1; ++i) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    a--;
    b--;
    g[a].emplace_back(b, t);
    g[b].emplace_back(a, t);
    edges.emplace_back(c, a, b);
  }

  vector<vector<int>> fa(N, vector<int>(20, -1));
  vector<vector<int>> fe(N, vector<int>(20, -1));
  vector<int> dep(N), dfn(N);

  auto Dfs = [&](auto dfs, int x, int p = -1, int fw = -1) -> void {
    static int stamp = 0;
    dfn[x] = stamp++;
    dep[x] = ~p ? dep[p] + 1 : 0;
    fa[x][0] = p;
    fe[x][0] = fw;
    for (int i = 1; (1 << i) <= dep[x]; ++i) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
      fe[x][i] = max(fe[x][i - 1], fe[fa[x][i - 1]][i - 1]);
    }
    for (auto [u, w] : g[x]) {
      if (u == p) continue;
      dfs(dfs, u, x, w);
    }
  };

  auto Query = [&](int x, int y) {
    if (dep[x] > dep[y]) {
      swap(x, y);
    }
    int res = 0;
    for (int k = 19; k >= 0; --k) {
      if ((dep[y] - dep[x]) >> k & 1) {
        res = max(res, fe[y][k]);
        y = fa[y][k];
      }
    }
    if (x == y) {
      return res;
    }
    for (int k = 19; k >= 0; --k) {
      if (fa[x][k] != fa[y][k]) {
        res = max(res, fe[x][k]);
        res = max(res, fe[y][k]);
        x = fa[x][k];
        y = fa[y][k];
      }
    }
    res = max(res, fe[x][0]);
    res = max(res, fe[y][0]);
    return res;
  };

  Dfs(Dfs, 0);
  vector<int> rev(N);
  for (int i = 0; i < N; ++i) {
    rev[dfn[i]] = i;
  }

  vector<tuple<int, int, int>> query;
  for (int i = 0; i < Q; ++i) {
    int v, x;
    cin >> v >> x;
    x--;
    query.emplace_back(v, x, i);
  }
  sort(query.rbegin(), query.rend());
  sort(edges.rbegin(), edges.rend());

  vector<int> uf(N);
  vector<set<int>> vec(N);
  vector<int> best(e.begin(), e.end());
  vector<int> dp(N);
  iota(uf.begin(), uf.end(), 0);

  for (int i = 0; i < N; ++i) {
    vec[i].insert(dfn[i]);
  }

  function<int(int)> Find = [&](int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
  };

  auto Merge = [&](int x, int y) {
    x = Find(x);
    y = Find(y);
    assert(x != y);
    if (best[x] > best[y]) {
      uf[y] = x;
      return;
    }
    if (best[y] > best[x]) {
      uf[x] = y;
      return;
    }
    if (vec[x].size() < vec[y].size()) {
      swap(x, y);
    }
    dp[x] = max(dp[x], dp[y]);
    for (int v : vec[y]) {
      auto iter = vec[x].lower_bound(v);
      if (iter != vec[x].end()) {
        dp[x] = max(dp[x], Query(rev[v], rev[*iter]));
      }
      if (iter != vec[x].begin()) {
        dp[x] = max(dp[x], Query(rev[v], rev[*prev(iter)]));
      }
    }
    for (int v : vec[y]) {
      vec[x].insert(v);
    }
    if (vec[x].size() >= 2) {
      dp[x] = max(dp[x], Query(rev[*vec[x].begin()], rev[*vec[x].rbegin()]));
    }
    uf[y] = x;
  };

  vector<pair<int, int>> ans(Q);
  for (int i = 0, j = 0; i < Q; ++i) {
    while (j < N - 1 && get<0>(edges[j]) >= get<0>(query[i])) {
      Merge(get<1>(edges[j]), get<2>(edges[j]));
      j++;
    }
    int x = get<1>(query[i]);
    int y = Find(x);
    int res = dp[y];
    auto iter = vec[y].lower_bound(dfn[x]);
    if (iter != vec[y].end()) {
      res = max(res, Query(x, rev[*iter]));
    }
    if (iter != vec[y].begin()) {
      res = max(res, Query(x, rev[*prev(iter)]));
    }
    int idx =get<2>(query[i]);
    ans[idx] = make_pair(best[y], res);
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}