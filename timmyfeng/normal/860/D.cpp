#include <bits/stdc++.h>
using namespace std;

const int N = 200'000;

vector<array<int, 3>> ans;
vector<int> adj[N];
int color[N];

int dfs(int u, int p) {
  vector<int> cities;
  color[u] = 1;

  for (auto c : adj[u]) {
    if (c != p && color[c] != 2) {
      if (color[c] == 1) {
        cities.push_back(c);
      } else {
        int v = dfs(c, u);
        if (v != -1) {
          ans.push_back({v, c, u});
        } else {
          cities.push_back(c);
        }
      }
    }
  }

  for (int i = 0; i + 1 < int(cities.size()); i += 2) {
    ans.push_back({cities[i], u, cities[i + 1]});
  }

  color[u] = 2;
  if (cities.size() % 2 == 1u) {
    return cities.back();
  } else {
    return -1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      dfs(i, -1);
    }
  }

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    for (auto j : i) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}