/**
 *    author:  tourist
 *    created: 19.05.2022 18:50:20       
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
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
      cin >> q[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[q[i]] += 1;
    }
    multiset<int> a;
    multiset<int> b;
    for (auto& p : mp) {
      b.insert(p.second);
    }
    int sum = 0;
    int ans = (int) 1e9;
    int holes = 0;
    for (int mex = 0; mex <= n; mex++) {
      while (!b.empty() && sum + (*b.begin()) <= k) {
        sum += (*b.begin());
        a.insert(*b.begin());
        b.erase(b.begin());
      }
      if (holes <= k) {
        ans = min(ans, (int) b.size());
      }
      auto it = mp.find(mex);
      if (it == mp.end()) {
        holes += 1;
      } else {
        if (a.find(it->second) != a.end()) {
          sum -= it->second;
          a.erase(a.find(it->second));
        } else {
          b.erase(b.find(it->second));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}