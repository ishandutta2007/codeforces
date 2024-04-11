#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

vector<int> adj[N], jda[N], order;
bool visited[N];
int color[N];

void add(int u, int v) {
  adj[u ^ 1].push_back(v);
  jda[v].push_back(u ^ 1);
  adj[v ^ 1].push_back(u);
  jda[u].push_back(v ^ 1);
}

void dfs_order(int u) {
  visited[u] = true;
  for (auto c : adj[u]) {
    if (!visited[c]) {
      dfs_order(c);
    }
  }
  order.push_back(u);
}

void dfs_color(int u, int x) {
  color[u] = x;
  for (auto c : jda[u]) {
    if (color[c] == 0) {
      dfs_color(c, x);
    }
  }
}

map<int, vector<int>> degree[N];
vector<array<int, 2>> exprs;
int t[N], n, m, k;

pair<bool, vector<int>> solve(int x) {
  fill(adj, adj + 2 * k, vector<int>());
  fill(jda, jda + 2 * k, vector<int>());
  fill(visited, visited + 2 * k, false);
  fill(color, color + 2 * k, 0);

  for (int i = 0; i < m; ++i) {
    if (t[i] > x) {
      add(2 * i + 1, 2 * i + 1);
    }
  }

  for (auto [u, v] : exprs) {
    add(u, v);
  }

  for (int i = 0; i < 2 * k; ++i) {
    if (!visited[i]) {
      dfs_order(i);
    }
  }

  int c = 0;
  while (!order.empty()) {
    int u = order.back();
    order.pop_back();
    if (!color[u]) {
      dfs_color(u, ++c);
    }
  }

  bool ok = true;
  vector<int> edges;
  for (int i = 0; i < k; ++i) {
    ok &= (color[2 * i] != color[2 * i + 1]);
    if (i < m && color[2 * i] > color[2 * i + 1]) {
      edges.push_back(i);
    }
  }

  return {ok, edges};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  k = m;

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c >> t[i];
    degree[--u][c].push_back(i);
    degree[--v][c].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    bool prefix = false;
    for (auto &[c, e] : degree[i]) {
      if (e.size() > 2) {
        cout << "No\n";
        exit(0);
      } else if (e.size() == 2) {
        exprs.push_back({2 * e[0], 2 * e[1]});
      }

      for (auto j : e) {
        if (prefix) {
          exprs.push_back({2 * j + 1, 2 * k - 1});
          exprs.push_back({2 * k - 1, 2 * k});
        }
        exprs.push_back({2 * j + 1, 2 * k++});
        prefix = true;
      }
    }
  }

  int l = 0, r = INT_MAX;
  while (l < r) {
    int x = l + (r - l) / 2;
    if (solve(x).first) {
      r = x;
    } else {
      l = x + 1;
    }
  }

  if (l == INT_MAX) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    vector<int> ans = solve(l).second;
    cout << l << " " << ans.size() << "\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}