/**
 *    author:  tourist
 *    created: 23.02.2022 13:19:10       
**/
#undef _GLIBCXX_DEBUG

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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j + 1];
    }
    cin >> a[i][0];
  }
  sort(a.begin(), a.end());
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    w[i] = a[i][0];
    a[i].erase(a[i].begin());
  }
  map<int, int> mp;
  int t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto it = mp.find(a[i][j]);
      if (it == mp.end()) {
        mp[a[i][j]] = t;
        a[i][j] = t++;
      } else {
        a[i][j] = it->second;
      }
    }
  }
  vector<unsigned long long> mask(t, -1);
  const unsigned long long one = 1;
  const int inf = (int) 2.01e9;
  int ans = inf;
  for (int L = 0; L < n; L += 64) {
    int R = min(L + 64, n);
    unsigned long long init = 0;
    for (int i = L; i < R; i++) {
      init |= (one << (i - L));
      for (int j = 0; j < m; j++) {
        mask[a[i][j]] ^= (one << (i - L));
      }
    }
    for (int i = L; i < n; i++) {
      unsigned long long cur = init;
      for (int j = 0; j < m; j++) {
        cur &= mask[a[i][j]];
      }
      if (cur > 0) {
        int id = L + __builtin_ctzll(cur);
        ans = min(ans, w[i] + w[id]);
      }
    }
    for (int i = L; i < R; i++) {
      for (int j = 0; j < m; j++) {
        mask[a[i][j]] ^= (one << (i - L));
      }
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  debug(clock());
  return 0;
}