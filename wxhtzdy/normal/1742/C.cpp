/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 16:37:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n = 8;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }           
    char ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == string(n, 'R')) {
        ans = 'R';
      }
    }
    for (int i = 0; i < n; i++) {
      string str = "";
      for (int j = 0; j < n; j++) {
        str += s[j][i];
      }
      if (str == string(n, 'B')) {
        ans = 'B';
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}