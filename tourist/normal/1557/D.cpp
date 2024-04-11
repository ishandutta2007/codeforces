/**
 *    author:  tourist
 *    created: 09.08.2021 17:43:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e;
  for (int i = 0; i < m; i++) {
    int r, c1, c2;
    cin >> r >> c1 >> c2;
    --r; --c1; --c2;
    e.emplace_back(c1, r);
    e.emplace_back(c2 + 1, ~r);
  }
  sort(e.begin(), e.end());
  vector<vector<int>> g(n);
  map<int, int> mp;
  int beg = 0;
  while (beg < (int) e.size()) {
    int end = beg;
    while (end + 1 < (int) e.size() && e[end + 1].first == e[end].first) {
      ++end;
    }
    for (int i = beg; i <= end; i++) {
      int id = e[i].second;
      if (id >= 0) {
        auto it = mp.lower_bound(id);
        if (it != mp.end() && it->first == id) {
          it->second += 1;
          continue;
        }
        if (it != mp.begin()) {
          int x = prev(it)->first;
          g[x].push_back(id);
        }
        if (it != mp.end()) {
          int y = it->first;
          g[id].push_back(y);
        }
        mp[id] = 1;
      } else {
        id = ~id;
        auto it = mp.find(id);
        assert(it != mp.end());
        if (it->second > 1) {
          it->second -= 1;
          continue;
        }
        if (it != mp.begin() && next(it) != mp.end()) {
          int x = prev(it)->first;
          int y = next(it)->first;
          g[x].push_back(y);
        }
        mp.erase(it);
      }
    }
    beg = end + 1;
  }
  vector<int> dp(n, 1);
  vector<int> pr(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      if (dp[i] + 1 > dp[j]) {
        dp[j] = dp[i] + 1;
        pr[j] = i;
      }
    }
  }
  int j = (int) (max_element(dp.begin(), dp.end()) - dp.begin());
  vector<bool> keep(n, false);
  while (j >= 0) {
    keep[j] = true;
    j = pr[j];
  }
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    if (!keep[i]) {
      ret.push_back(i);
    }
  }
  cout << ret.size() << '\n';
  for (int i = 0; i < (int) ret.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ret[i] + 1;
  }
  cout << '\n';
  return 0;
}