/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 11:05:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  string s, t;
  cin >> s >> t;
  int n = (int) s.size();
  int m = (int) t.size();
  string ans = s + t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = min(ans, s.substr(0, i + 1) + t.substr(0, j + 1));
    }
  }
  cout << ans << '\n';                                                                    
  return 0;
}