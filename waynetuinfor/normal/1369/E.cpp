#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<vector<pair<int, int>>> g(n);
  vector<int> deg(n);
  vector<int> u(m), v(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    g[u[i]].emplace_back(v[i], i);
    g[v[i]].emplace_back(u[i], i);
    deg[u[i]]++;
    deg[v[i]]++;
  }
  vector<int> que;
  vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    if (deg[i] <= w[i]) {
      que.push_back(i);
      used[i] = true;
    }
  }
  vector<bool> pushed(m);
  vector<int> res;
  for (int it = 0; it < que.size(); ++it) {
    int x = que[it];
    for (auto e : g[x]) {
      if (!pushed[e.second]) {
        pushed[e.second] = true;
        res.push_back(e.second);
      }
      if (!used[e.first] && --deg[e.first] == w[e.first]) {
        used[e.first] = true;
        que.push_back(e.first);
      }
    }
  }
  if (res.size() < m) {
    cout << "DEAD\n";
    return 0;
  }
  reverse(res.begin(), res.end());
  vector<int> r(w.begin(), w.end());
  for (int i = 0; i < m; ++i) {
    if (r[u[res[i]]] == 0 && r[v[res[i]]] == 0) {
      cout << "DEAD\n";
      return 0;
    }
    if (r[u[res[i]]] > 0) r[u[res[i]]]--;
    if (r[v[res[i]]] > 0) r[v[res[i]]]--;
  }
  cout << "ALIVE\n";
  for (int u : res) cout << u + 1 << " ";
  cout << "\n";
}