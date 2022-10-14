/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 17:13:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  vector<multiset<int>> xa(n + m);
  vector<multiset<int>> xb(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      xa[i + j].insert(a[i][j]);
      xb[i + j].insert(b[i][j]);
    }
  }
  bool ok = true;
  for (int i = 0; i < n + m; i++) {
    if (xa[i] != xb[i]) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';                            
  return 0;
}