#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int L = 62;
  vector<vector<int>> pos(L);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < L; j++) {
      if (a[i] & (1LL << j)) {
        pos[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < L; i++) {
    if (pos[i].size() > 2) {
      cout << 3 << '\n';
      return 0;
    }
  }
  vector<pair<int, int>> e;
  for (int j = 0; j < L; j++) {
    for (int u : pos[j]) {
      for (int v : pos[j]) {
        if (u != v) {
          e.emplace_back(min(u, v), max(u, v));
        }
      }
    }
  }
  sort(e.begin(), e.end());
  e.erase(unique(e.begin(), e.end()), e.end());
  int ans = 1e9;
  vector<vector<int>> g(n);
  vector<int> dist(n);
  function<void(int)> Bfs = [&](int u) {
    dist[u] = 0;
    vector<int> que(1, u);
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (dist[j] == 1e9) {
          que.push_back(j);
        }
        dist[j] = min(dist[j], dist[que[b]] + 1);
      }
    }
  };
  for (int i = 0; i < (int) e.size(); i++) {
    for (int j = 0; j < n; j++) {
      g[j].clear();
      dist[j] = 1e9;
    }
    for (int j = 0; j < (int) e.size(); j++) {
      if (i != j) {
        g[e[j].first].push_back(e[j].second);
        g[e[j].second].push_back(e[j].first);
      }
    }
    Bfs(e[i].first);
    if (dist[e[i].second] != 1e9) {
      ans = min(ans, dist[e[i].second] + 1);
    }
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
  return 0;
}