/**
 *    author:  milos
 *    created: 31.07.2020 12:01:59      
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      if (i > 0 && s[i - 1][j] == 'o') cnt++;
      if (i < n - 1 && s[i + 1][j] == 'o') cnt++;
      if (j > 0 && s[i][j - 1] == 'o') cnt++;
      if (j < n - 1 && s[i][j + 1] == 'o') cnt++;
      if (cnt % 2 == 1) ok = 0;      
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;   
}