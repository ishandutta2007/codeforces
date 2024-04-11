#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int weight[N];
int color[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> edges;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u - 1, v - 1});
  }

  for (int i = 0; i < n; ++i) {
    cin >> color[i];
  }

  int total = 0;
  for (auto [u, v] : edges) {
    if (color[u] != color[v]) {
      ++weight[u];
      ++weight[v];
      ++total;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (weight[i] == total) {
      cout << "YES\n";
      cout << i + 1 << "\n";
      exit(0);
    }
  }

  cout << "NO\n";
}