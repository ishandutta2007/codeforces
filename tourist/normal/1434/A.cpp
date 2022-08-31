/**
 *    author:  tourist
 *    created: 25.10.2020 14:04:52       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 6;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<vector<int>> x(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      x[i][j] = b[i] - a[j];
    }
    sort(x[i].begin(), x[i].end());
  }
  vector<pair<int, int>> p;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      p.emplace_back(x[i][j], i);
    }
  }
  sort(p.begin(), p.end());
  multiset<int> s;
  for (int i = 0; i < m; i++) {
    s.insert(x[i][0]);
  }
  vector<int> ptr(m, 0);
  int ans = (int) 2e9;
  {
    int mn = *s.begin();
    int mx = *prev(s.end());
    ans = min(ans, mx - mn);
  }
  for (auto& q : p) {
    int i = q.second;
    s.erase(s.find(x[i][ptr[i]]));
    ++ptr[i];
    if (ptr[i] == n) {
      break;
    }
    s.insert(x[i][ptr[i]]);
    int mn = *s.begin();
    int mx = *prev(s.end());
    ans = min(ans, mx - mn);
  }
  cout << ans << '\n';
  return 0;
}