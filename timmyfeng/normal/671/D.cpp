#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;

struct lazy_map {

  map<int, long long> values;
  multiset<long long> costs;
  long long mini, lazy;

  lazy_map() {
    mini = LLONG_MAX;
    lazy = 0;
  }

  void insert(int a, long long c) {
    if (!values.count(a)) {
      values[a] = c - lazy;
      costs.insert(c - lazy);
    } else if (c - lazy < values[a]) {
      costs.erase(costs.find(values[a]));
      values[a] = c - lazy;
      costs.insert(c - lazy);
    }
    mini = *costs.begin() + lazy;
  }

  void erase(int a) {
    if (values.count(a)) {
      costs.erase(costs.find(values[a]));
      values.erase(a);
    }
    mini = costs.empty() ? LLONG_MAX : *costs.begin() + lazy;
  }

  void add(long long c) {
    lazy += c;
    if (mini < LLONG_MAX) {
      mini += c;
    }
  }

};

vector<array<int, 2>> workers[N];
vector<int> adj[N];
int depth[N], n;

lazy_map * dfs(int u, int p = 0) {
  lazy_map *lu = new lazy_map();
  lu->insert(depth[u], 0);

  for (auto c : adj[u]) {
    if (c != p) {
      depth[c] = depth[u] + 1;
      lazy_map *lc = dfs(c, u);

      lc->erase(depth[c]);
      long long child = lc->mini;
      if (child == LLONG_MAX) {
        cout << -1 << "\n";
        exit(0);
      }

      lc->add(lu->mini);
      lu->add(child);

      if (lu->values.size() < lc->values.size()) {
        swap(lu, lc);
      }

      for (auto [a, c] : lc->values) {
        lu->insert(a, c + lc->lazy);
      }
    }
  }

  if (lu->mini == LLONG_MAX) {
    cout << -1 << "\n";
    exit(0);
  }

  for (auto [v, c] : workers[u]) {
    lu->insert(depth[v], lu->mini + c);
  }

  return lu;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    workers[u].push_back({v, c});
  }

  cout << dfs(1)->mini << "\n";
}