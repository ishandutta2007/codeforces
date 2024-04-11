/**
 *    author:  tourist
 *    created: 03.06.2022 18:52:03       
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y + 1);
      g[y + 1].push_back(x);
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + b[i] - a[i];
    }
    set<int> s;
    vector<int> que;
    for (int i = 0; i <= n; i++) {
      if (pref[i] == 0) {
        que.push_back(i);
      } else {
        s.insert(i);
      }
    }
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b];
      for (int j : g[i]) {
        if (pref[j] != 0) {
          continue;
        }
        int L = i;
        int R = j;
        if (L > R) {
          swap(L, R);
        }
        auto it = s.lower_bound(L);
        while (it != s.end() && *it <= R) {
          que.push_back(*it);
          pref[*it] = 0;
          it = s.erase(it);
        }
      }
    }
    cout << ((int) que.size() == n + 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}