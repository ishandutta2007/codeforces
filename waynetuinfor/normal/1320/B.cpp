#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), r(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    r[v].push_back(u);
  }
  int k;
  cin >> k;
  vector<int> p(k);
  for (int i = 0; i < k; ++i) {
    cin >> p[i];
    p[i]--;
  }
  set<pair<int, int>> s;
  for (int i = 0; i + 1 < k; ++i) s.insert(make_pair(p[i], p[i + 1]));

  vector<int> que(1, p[k - 1]);
  vector<int> dist(n, -1);
  dist[p[k - 1]] = 0;
  for (int i = 0; i < que.size(); ++i) {
    int x = que[i];
    for (int u : r[x]) {
      if (dist[u] == -1) {
        dist[u] = dist[x] + 1;
        que.push_back(u);
      }
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i + 1 < k; ++i) {
    if (dist[p[i + 1]] + 1 != dist[p[i]]) {
      a++;
      b++;
    } else {
      bool ok = false;
      for (int u : g[p[i]]) {
        if (u == p[i + 1]) continue;
        if (dist[u] + 1 == dist[p[i]]) ok = true;
      }
      if (ok) b++;
    }
  }
  cout << a << ' ' << b << "\n";
}