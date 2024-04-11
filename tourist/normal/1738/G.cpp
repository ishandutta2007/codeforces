/**
 *    author:  tourist
 *    created: 30.09.2022 18:47:03       
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<pair<int, int>> all;
    for (int j = n - k + 1; j >= 0; j--) {
      all.emplace_back(0, j);
    }
    for (int i = 1; i <= n - k + 1; i++) {
      all.emplace_back(i, 0);
    }
    int sz = (int) all.size();
    vector<int> when(sz, -1);
    int T = 0;
    vector<string> res(n, string(n, '0'));
    for (int it = 0; it < k - 1; it++) {
      vector<int> idx;
      for (int i = 1; i < sz - 1; i++) {
        idx.push_back(i);
      }
      while (!idx.empty()) {
        vector<int> new_idx;
        ++T;
        auto Add = [&](int id) {
          if (id > 0 && id < sz - 1 && when[id] != T) {
            new_idx.push_back(id);
            when[id] = T;
          }
        };
        for (int i : idx) {
          if (all[i - 1].first == all[i].first && all[i + 1].second == all[i].second) {
            if (s[all[i].first][all[i].second] == '1') {
              all[i].first += 1;
              all[i].second += 1;
              Add(i - 1);
              Add(i + 1);
            }
          }
        }
        swap(idx, new_idx);
      }
      for (auto& p : all) {
        res[p.first][p.second] = '1';
        p.first += 1;
        p.second += 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (abs(i - j) > n - k) {
          res[i][j] = '1';
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (res[i][j] == '0' && s[i][j] == '0') {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << res[i] << '\n';
    }
  }
  return 0;
}