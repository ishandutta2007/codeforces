/**
 *    author:  tourist
 *    created: 01.08.2022 17:54:11       
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
    int n;
    cin >> n;
    vector<vector<array<int, 3>>> g(n);
    for (int y = 1; y < n; y++) {
      int x, w0, w1;
      cin >> x >> w0 >> w1;
      --x;
      g[x].push_back({y, w0, w1});
      g[y].push_back({x, w0, w1});
    }
    vector<long long> seq(1, 0);
    vector<int> res(n);
    function<void(int, int, long long)> Dfs = [&](int v, int pr, long long s) {
      if (v > 0) {
        res[v] = (int) (lower_bound(seq.begin(), seq.end(), s + 1) - seq.begin()) - 1;
      }
      for (auto& p : g[v]) {
        int u = p[0];
        if (u == pr) {
          continue;
        }
        seq.push_back(seq.back() + p[2]);
        Dfs(u, v, s + p[1]);
        seq.pop_back();
      }
    };
    Dfs(0, -1, 0);
    for (int i = 1; i < n; i++) {
      cout << res[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}