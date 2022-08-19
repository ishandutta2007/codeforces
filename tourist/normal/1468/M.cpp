/**
 *    author:  tourist
 *    created: 25.12.2020 16:58:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> sz(n);
    vector<tuple<int, int, int>> xs;
    for (int i = 0; i < n; i++) {
      cin >> sz[i];
      a[i].resize(sz[i]);
      for (int j = 0; j < sz[i]; j++) {
        cin >> a[i][j];
        xs.emplace_back(a[i][j], i, j);
      }
    }
    sort(xs.begin(), xs.end());
    int t = 0;
    for (int i = 0; i < (int) xs.size(); i++) {
      if (i > 0 && get<0>(xs[i]) != get<0>(xs[i - 1])) {
        ++t;
      }
      a[get<1>(xs[i])][get<2>(xs[i])] = t;
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return sz[i] > sz[j];
    });
    vector<bool> was(t + 1, false);
    int total = accumulate(sz.begin(), sz.end(), 0);
    int ax = -1;
    int ay = -1;
    int ptr = 0;
    while (ptr < n && (long long) sz[order[ptr]] * sz[order[ptr]] >= total) {
      int i = order[ptr];
      for (int x : a[i]) {
        was[x] = true;
      }
      for (int it = ptr + 1; it < n; it++) {
        int j = order[it];
        int cnt = 0;
        for (int y : a[j]) {
          if (was[y]) {
            cnt += 1;
          }
        }
        if (cnt >= 2) {
          ax = i;
          ay = j;
          break;
        }
      }
      for (int x : a[i]) {
        was[x] = false;
      }
      if (ax != -1) {
        break;
      }
      ptr += 1;
    }
    if (ax == -1) {
      vector<vector<int>> by_a(t + 1);
      for (int it = ptr; it < n; it++) {
        int i = order[it];
        for (int x : a[i]) {
          by_a[x].push_back(i);
        }
      }
      vector<int> who(t + 1, -1);
      for (int val = 0; val <= t; val++) {
        for (int i : by_a[val]) {
          for (int x : a[i]) {
            if (x == val) {
              continue;
            }
            if (who[x] != -1) {
              ax = who[x];
              ay = i;
            } else {
              who[x] = i;
            }
          }
        }
        if (ax != -1) {
          break;
        }
        for (int i : by_a[val]) {
          for (int x : a[i]) {
            who[x] = -1;
          }
        }
      }
    }
    if (ax == -1) {
      cout << -1 << '\n';
    } else {
      cout << ax + 1 << " " << ay + 1 << '\n';
    }
  }
  return 0;
}