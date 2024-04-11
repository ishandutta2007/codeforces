/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:15:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if ((int) s.size() != 3) {
      cout << "NO" << '\n';
      continue;
    }
    if (s[0] == 'y') {
      s[0] = 'Y';  
    }
    if (s[1] == 'e') {
      s[1] = 'E';  
    }
    if (s[2] == 's') {
      s[2] = 'S';  
    }
    if (s == "YES") {
      cout << s << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }                                                                    
  return 0;
}