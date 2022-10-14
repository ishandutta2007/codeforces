#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dist(n, -1);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    if (i - a[i] >= 0) {
      if (a[i - a[i]] % 2 != a[i] % 2) {
        dist[i] = 1;
      } else {
        g[i - a[i]].push_back(i);
      }
    }
    if (i + a[i] < n) {
      if (a[i + a[i]] % 2 != a[i] % 2) {
        dist[i] = 1;
      } else {
        g[i + a[i]].push_back(i);
      }
    }
  }
  for (int k = 0; k < 2; k++) {
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == k && dist[i] == 1) {
        s.insert({1, i});
      }
    }
    while (!s.empty()) {
      int x = (*s.begin()).second;
      s.erase(s.begin());
      for (int j : g[x]) {
        if (dist[j] == -1 || dist[j] > dist[x] + 1) {
          s.erase({dist[j], j});
          dist[j] = dist[x] + 1;
          s.insert({dist[j], j});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i] << " ";
  }
  cout << '\n';
  return 0;
}