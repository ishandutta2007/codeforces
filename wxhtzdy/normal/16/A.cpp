/**
 *    author:  milos
 *    created: 28.01.2021 07:40:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (s[i][j] != s[i][j - 1]) {
        ok = false;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i][0] == s[i - 1][0]) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}