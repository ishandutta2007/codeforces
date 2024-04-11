/**
 *    author:  milos
 *    created: 22.09.2021 18:15:00       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
// idea by tourist

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  vector<vector<int>> b(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      b[i][j]--;
    }
  }
  sort(b.begin(), b.end());
  set<pair<int, vector<int>>> s;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i].back();
  }               
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = c[i] - 1;
  }
  s.insert(make_pair(sum, p));
  while (true) {
    auto it = prev(s.end());
    int sum = it -> first;
    vector<int> p = it -> second;
    s.erase(it);
    auto it2 = lower_bound(b.begin(), b.end(), p);
    if (it2 == b.end() || *it2 != p) {
      for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " "; 
      }
      cout << '\n';
      break;
    }
    for (int i = 0; i < n; i++) {
      if (p[i] > 0) {
        int S = sum - a[i][p[i]] + a[i][p[i] - 1];
        p[i]--;
        s.insert(make_pair(S, p));
        p[i]++;
      }
    }
  }
  return 0;
}