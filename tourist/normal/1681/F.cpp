/**
 *    author:  tourist
 *    created: 23.05.2022 18:44:02       
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
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b; --c;
    g[c].emplace_back(a, b);
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  vector<int> sz(n, 1);
  vector<pair<int, int>> ops;
  auto Get = [&](int i) {
    while (i != p[i]) {
      i = p[i];
    }
    return i;
  };
  auto Unite = [&](int i, int j) {
    i = Get(i);
    j = Get(j);
    if (i != j) {
      if (sz[i] > sz[j]) {
        swap(i, j);
      }
      ops.emplace_back(i, p[i]);
      p[i] = j;
      ops.emplace_back(~j, sz[j]);
      sz[j] += sz[i];
    }
  };
  auto Rollback = [&](int T) {
    while ((int) ops.size() > T) {
      int i = ops.back().first;
      int j = ops.back().second;
      ops.pop_back();
      if (i >= 0) {
        p[i] = j;
      } else {
        sz[~i] = j;
      }
    }
  };
  long long ans = 0;
  function<void(int, int)> Dfs = [&](int l, int r) {
    if (l == r) {
      for (auto& p : g[l]) {
        int x = Get(p.first);
        int y = Get(p.second);
        ans += (long long) sz[x] * sz[y];
      }
      return;
    }
    int mid = (l + r) >> 1;
    {
      int save = (int) ops.size();
      bool fail = false;
      for (int i = mid + 1; i <= r; i++) {
        for (auto& p : g[i]) {
          Unite(p.first, p.second);
        }
      }
      Dfs(l, mid);
      Rollback(save);
    }
    {
      int save = (int) ops.size();
      bool fail = false;
      for (int i = l; i <= mid; i++) {
        for (auto& p : g[i]) {
          Unite(p.first, p.second);
        }
      }
      Dfs(mid + 1, r);
      Rollback(save);
    }
  };
  Dfs(0, n - 1);
  cout << ans << '\n';
  return 0;
}