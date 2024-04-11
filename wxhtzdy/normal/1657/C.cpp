/**
 *    author:  wxhtzdy
 *    created: 15.06.2022 18:31:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;                                 
    int ops = 0;
    int len = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '(') {
        ops += 1;
        len += 2;
        i += 1;
        continue;
      }
      int ptr = i + 1;      
      while (ptr < n && s[ptr] != s[i]) {
        ptr += 1;
      }
      if (ptr < n) {
        ops += 1;
        len += ptr - i + 1;
        i = ptr;
      } else {
        break;
      }
    }
    cout << ops << " " << n - len << '\n';
  }                                                                    
  return 0;
}