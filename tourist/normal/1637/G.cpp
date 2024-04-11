/**
 *    author:  tourist
 *    created: 12.02.2022 18:31:06       
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
    if (n == 2) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<pair<int, int>> ops;
    auto Do = [&](int i, int j) {
      int x = a[i];
      int y = a[j];
      a[i] = x + y;
      a[j] = abs(x - y);
      ops.emplace_back(x, y);
    };
    function<void(vector<int>)> Dfs = [&](vector<int> ids) {
      sort(ids.begin(), ids.end(), [&](int i, int j) {
        return a[i] < a[j];
      });
      int sz = (int) ids.size();
      for (int i = 0; i < sz; i++) {
        assert(a[ids[i]] == a[ids[0]] * (i + 1));
      }
      if (sz <= 2) {
        return;
      }
      int x = 1;
      while (x < sz) {
        x *= 2;
      }
      vector<int> down;
      vector<int> up;
      for (int i = 0; i < x - 2 - i; i++) {
        if (x - 2 - i < sz) {
          Do(ids[i], ids[x - 2 - i]);
          up.push_back(ids[x - 2 - i]);
        } else {
          down.push_back(ids[i]);
        }
      }
      Dfs(down);
      Dfs(up);
    };
    vector<int> init(n);
    iota(init.begin(), init.end(), 0);
    Dfs(init);
    int mx = *max_element(a.begin(), a.end());
    map<int, int> was;
    int zero = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != mx) {
        if (was.find(a[i]) != was.end()) {
          Do(was[a[i]], i);
          zero = i;
          break;
        }
        was[a[i]] = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] != 0 && a[i] < mx) {
        while (a[i] < mx) {
          Do(i, zero);
          Do(i, zero);
        }
      }
    }
    int other = (zero == 0 ? 1 : 0);
    Do(other, zero);
    cout << ops.size() << '\n';
    for (auto& p : ops) {
      cout << p.first << " " << p.second << '\n';
    }
  }
  return 0;
}