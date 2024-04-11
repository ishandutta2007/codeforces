#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int xorko = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      xorko ^= a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (xorko == 0) {
      cout << "YES" << '\n';
      continue;
    }
    if (k == 2) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> xr(n), par(n);
    int who = -1;
    function<void(int, int)> Dfs = [&](int u, int p) {
      par[u] = p;
      xr[u] = a[u];
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        Dfs(v, u);
        xr[u] ^= xr[v];
      }
      if (who == -1 && xr[u] == xorko) {
        who = u;
      }
    };
    Dfs(0, 0);
    if (who <= 0) {
      cout << "NO" << '\n';
      continue;
    }
    function<void(int, int)> Rem = [&](int u, int p) {
      a[u] = 0;
      for (int v : g[u]) {
        if (v == p) {
          continue;
        }
        Rem(v, u);
      }
    };
    Rem(who, par[who]);
    who = -1;
    Dfs(0, 0);
    if (who <= 0) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
  return 0;
}