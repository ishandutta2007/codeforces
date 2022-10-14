/**
 *    author:  milos
 *    created: 09.08.2021 21:30:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i + 1][j + 1] == 'X') {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}