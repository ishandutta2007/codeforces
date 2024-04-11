/**
 *    author:  milos
 *    created: 01.04.2021 16:39:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  bool ok = true;
  for (int i = 2; i < n; i++) {
    if (s[i] - 'A' != (s[i - 1] - 'A' + s[i - 2] - 'A') % 26) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}