/**
 *    author:  milos
 *    created: 25.04.2021 08:24:53       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      cnt++;
    } else {
      break;
    }
  }
  int ans = cnt;
  for (int i = n - 1; i >= 0; i--) {
    if (i < cnt) {
      break;
    }
    if (i < n - 1 && s[i] == s[i + 1]) {
      break;
    }                 
    if (s[n - 1] != s[0]) {
      ans = max(ans, cnt + n - i);
    }
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      cnt++;
    } else {
      cnt = 1;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}