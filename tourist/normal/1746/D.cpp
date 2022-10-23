/**
 *    author:  tourist
 *    created: 15.10.2022 18:46:50       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      --x;
      g[x].push_back(i);
      g[i].push_back(x);
    }
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<long long> val(n);
    val[0] = k;
    vector<long long> add(n);
    long long ans = 0;
    function<void(int, int)> Dfs = [&](int v, int pr) {
      ans += val[v] * s[v];
      vector<int> children;
      for (int u : g[v]) {
        if (u == pr) {
          continue;
        }
        children.push_back(u);
      }
      int cnt = (int) children.size();
      vector<long long> aux;
      for (int u : children) {
        val[u] += val[v] / cnt;
        Dfs(u, v);
        aux.push_back(add[u]);
      }
      if (cnt > 0) {
        sort(aux.rbegin(), aux.rend());
        auto rm = val[v] % cnt;
        for (int i = 0; i < rm; i++) {
          ans += aux[i];
        }
        add[v] = s[v] + aux[rm];
      } else {
        add[v] = s[v];
      }
    };
    Dfs(0, -1);
    cout << ans << '\n';
  }
  return 0;
}