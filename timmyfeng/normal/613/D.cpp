#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int L = __lg(N) + 1;

int in[N], out[N], par[L][N], n, t;
vector<int> adj[N];

void dfs_init(int u) {
  in[u] = ++t;
  for (auto c : adj[u]) {
    if (c != par[0][u]) {
      par[0][c] = u;
      dfs_init(c);
    }
  }
  out[u] = t;
}

bool euler_compare(int u, int v) {
  return in[u] < in[v];
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
  if (ancestor(u, v)) {
    return u;
  }

  for (int i = __lg(n); i >= 0; --i) {
    if (!ancestor(par[i][u], v)) {
      u = par[i][u];
    }
  }
  return par[0][u];
}

vector<int> plan[N];
bool important[N];

array<int, 2> dfs_solve(int u, int p = 0) {
  int none = 0, one = 0, any = 0;
  for (auto c : plan[u]) {
    if (c != p) {
      array<int, 2> child = dfs_solve(c, u);
      one = min(one + child[0], none + child[1]);
      any += min(child[0], child[1]);
      none += child[0];
    }
  }

  if (important[u]) {
    return {none + 1, none};
  } else {
    return {min(any + 1, none), one};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_init(1);
  out[0] = t;

  for (int i = 1; i <= __lg(n); ++i) {
    for (int j = 1; j <= n; ++j) {
      par[i][j] = par[i - 1][par[i - 1][j]];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;

    vector<int> cities(k);
    for (auto &u : cities) {
      cin >> u;
      important[u] = true;
    }

    bool ok = true;
    for (auto u : cities) {
      ok &= !important[par[0][u]];
    }

    sort(cities.begin(), cities.end(), euler_compare);
    for (int i = 1; i < k; ++i) {
      cities.push_back(lca(cities[i - 1], cities[i]));
    }
    sort(cities.begin(), cities.end(), euler_compare);
    cities.erase(unique(cities.begin(), cities.end()), cities.end());

    vector<int> path;
    for (auto u : cities) {
      while (!path.empty() && !ancestor(path.back(), u)) {
        path.pop_back();
      }
      if (!path.empty()) {
        plan[path.back()].push_back(u);
      }
      path.push_back(u);
    }

    array<int, 2> ans = dfs_solve(path[0]);

    cout << (ok ? min(ans[0], ans[1]) : -1) << "\n";

    for (auto u : cities) {
      important[u] = false;
      plan[u].clear();
    }
  }
}