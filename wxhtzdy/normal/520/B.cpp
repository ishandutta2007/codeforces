#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  const int N = 2e4 + 5;
  vector<vector<int>> g(N);
  for (int i = 2; i < N; i++) {
    g[i].push_back(i - 1);
    if (i % 2 == 0) {
      g[i / 2].push_back(i);
    }
  }
  vector<int> dist(N, N);
  dist[a] = 0;
  set<pair<int, int>> s;
  s.insert({0, a});
  while (!s.empty()) {
    auto it = s.begin();
    int d = (*it).first;
    int x = (*it).second;
    s.erase(it);
    for (int y : g[x]) {
      if (dist[y] > d + 1) {
        s.erase({dist[y], y});
        dist[y] = d + 1;
        s.insert({dist[y], y});
      }
    }
  }
  cout << dist[b] << '\n';
  return 0;
}