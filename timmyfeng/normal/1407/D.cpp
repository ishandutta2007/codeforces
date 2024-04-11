#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> building;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    building.push_back({h, i});
  }
  sort(building.begin(), building.end());

  vector<vector<int>> adj(n);
  for (int k = 0; k < 2; ++k) {
    set<int> ndx;
    for (int j = 0; j < n; ++j) {
      auto [h, i] = building[j];
      auto it = ndx.upper_bound(i);
      if (it != ndx.end() && (j + 1 == n || building[j + 1][0] != h || building[j + 1][1] > *it)) {
        adj[i].push_back(*it);
      }
      if (it != ndx.begin()) {
        adj[*(--it)].push_back(i);
      }
      ndx.insert(i);
    }

    for (auto& [h, i] : building) {
      h = -h;
    }
    sort(building.begin(), building.end());
  }

  vector<int> dist(n, -1);
  queue<int> que;
  que.push(0);
  dist[0] = 0;

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto c : adj[u]) {
      if (dist[c] == -1) {
        dist[c] = dist[u] + 1;
        que.push(c);
      }
    }
  }

  cout << dist[n - 1] << "\n";
}