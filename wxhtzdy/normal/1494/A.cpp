/**
 *    author:  milos
 *    created: 02.03.2021 23:52:00       
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
    bool ok = false;
    for (int i = 0; i < (1 << 3); i++) {
      string t = "";
      for (int k = 0; k < (int) s.size(); k++) {
        int c = (int) (s[k] - 'A');
        if (i & (1 << c)) {
          t += '(';
        } else {
          t += ')';
        }
      }
      bool valid = true;
      int bal = 0;
      for (char c : t) {
        if (c == '(') {
          bal++;
        } else {
          bal--;
        }
        if (bal < 0) {
          valid = false;
        }
      }
      if (bal != 0) {
        valid = false;
      }
      if (valid) {
        ok = true;   
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}