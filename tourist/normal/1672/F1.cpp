/**
 *    author:  tourist
 *    created: 23.04.2022 19:10:34       
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
    vector<int> a(n);
    map<int, int> mp;
    vector<vector<pair<int, int>>> ps;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      int id = mp[a[i]];
      if (id >= (int) ps.size()) {
        ps.resize(id + 1);
      }
      ps[id].emplace_back(a[i], i);
      mp[a[i]] += 1;
    }
    auto b = a;
    for (auto& p : ps) {
      sort(p.begin(), p.end());
      for (int i = 0; i < (int) p.size(); i++) {
        b[p[i].second] = a[p[(i + 1) % (int) p.size()].second];
      }
    }
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}