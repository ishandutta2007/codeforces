/**
 *    author:  tourist
 *    created: 24.04.2022 15:51:25       
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
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> depth(n);
  for (int i = 1; i < n; i++) {
    depth[i] = depth[p[i]] + 1;
  }
  vector<int> sz(n, 1);
  for (int i = n - 1; i > 0; i--) {
    sz[p[i]] += sz[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    g[p[i]].push_back(i);
    g[i].push_back(p[i]);
  }
  int r = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (2 * sz[i] >= n) {
      r = i;
      break;
    }
  }
  long long ans = n;
  auto Solve = [&](vector<int> a) {
    vector<int> cnt(n + 1);
    for (int b : a) {
      cnt[b] += 1;
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[i] >= 4) {
        assert(2 * i <= n);
        int take = cnt[i] / 2 - 1;
        cnt[2 * i] += take;
        cnt[i] -= 2 * take;
      }
    }
    const int N = (int) 1e6 + 10;
    bitset<N> b;
    b[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        b |= (b << i);
      }
    }
    long long mx = 0;
    for (int i = 0; i < N; i++) {
      if (b[i]) {
        mx = max(mx, i * (n - 1LL - i));
      }
    } 
    ans += mx;
  };
  function<int(int, int, int)> Dfs = [&](int v, int pv, int d) {
    ans += d;
    vector<int> a;
    int s = 1;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      int got = Dfs(u, v, d + 1);
      a.push_back(got);
      s += got;
    }
    if (pv == -1) {
      Solve(a);
    }
    return s;
  };
  Dfs(r, -1, 0);
  cout << ans << '\n';
  return 0;
}