/**
 *    author:  tourist
 *    created: 20.09.2021 17:42:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  vector<vector<int>> f(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> f[i][j];
      --f[i][j];
    }
  }
  sort(f.begin(), f.end());
  set<pair<int, vector<int>>> s;
  {
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      sum += a[i].back();
      v[i] = c[i] - 1;
    }
    s.emplace(sum, v);
  }
  while (true) {
    assert(!s.empty());
    auto it = prev(s.end());
    int sum = it->first;
    vector<int> v = it->second;
    s.erase(it);
    auto iter = lower_bound(f.begin(), f.end(), v);
    if (iter == f.end() || *iter != v) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << v[i] + 1;
      }
      cout << endl;
      break;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > 0) {
        int new_sum = sum - a[i][v[i]] + a[i][v[i] - 1];
        v[i] -= 1;
        s.emplace(new_sum, v);
        v[i] += 1;
      }
      if (v[i] < c[i] - 1) {
        break;
      }
    }
  }
  return 0;
}