/**
 *  author: milos
 *  created: 14.12.2020 11:38:12
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> sz(N, 0), g(N);
vector<vector<int>> e(N);
vector<bool> was(N);

void Dfs(int u, int t) {
  was[u] = 1;
  g[u] = t, sz[t]++;
  for (auto v : e[u]) {
    if (!was[v]) {
      Dfs(v, t);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) e[i].clear(), sz[i] = 0, was[i] = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      e[i].push_back(a[i] - 1);
    }
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        Dfs(i, i);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << sz[g[i]] << " ";
    }
    cout << '\n';
  }
  return 0;
}