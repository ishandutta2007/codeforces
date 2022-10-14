/**
 *    author:  milos
 *    created: 25.09.2021 12:26:06       
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
  for (int i = 0; i < s[0].size(); i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (s[j][i] != s[0][i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      break;
    }
    ans++;
  }
  cout << ans << '\n';
  return 0;
}