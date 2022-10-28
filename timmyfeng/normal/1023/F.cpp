#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> size;

  union_find() {}

  union_find(int n) {
    par.resize(n);
    size.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (size[u] > size[v]) {
      swap(u, v);
    }
    par[u] = v;
    size[v] += size[u];
    return true;
  }

};

const int N = 500000 + 1;
const int L = __lg(N) + 1;

vector<int> adj[N];
int n;

union_find colors;
bool visited[N];

void dfs_colors(int u, int p = 0) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (c != p) {
      colors.unite(u, c);
      dfs_colors(c, u);
    }
  }
}

int par[N][L], in[N], out[N], t;

void dfs_par(int u) {
  for (int i = 1; i <= __lg(n); ++i) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }

  in[u] = ++t;
  for (auto c : adj[u]) {
    if (c != par[u][0]) {
      par[c][0] = u;
      dfs_par(c);
    }
  }
  out[u] = t;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

array<int, 3> compete[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, m;
  cin >> n >> k >> m;

  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  colors = union_find(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs_colors(i);
    }
  }

  union_find temp = colors;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (temp.find(u) != temp.find(v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      temp.unite(u, v);
    }
    compete[i] = {u, v, w};
  }

  dfs_par(1);
  out[0] = t;

  int count = 0;
  long long ans = 0;
  union_find dsu(n + 1);
  for (int i = 0; i < m; ++i) {
    auto [u, v, w] = compete[i];

    if (dsu.same(u, v)) {
      continue;
    }

    if (!colors.same(u, v)) {
      count += dsu.unite(u, v);
      colors.unite(u, v);
      continue;
    }

    while (!dsu.same(u, v)) {
      if (ancestor(u, v)) {
        swap(u, v);
      }

      for (int j = __lg(n); j >= 0; --j) {
        if (!ancestor(par[u][j], v) && dsu.same(u, par[u][j])) {
          u = par[u][j];
        }
      }

      if (dsu.unite(u, par[u][0])) {
        ans += w;
        ++count;
      }
      u = par[u][0];
    }
  }

  if (count < n - 1) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}