/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:31:46
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
    string t;
    cin >> t;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'G') {
        s[i] = 'B';
      }
      if (t[i] == 'G') {
        t[i] = 'B';
      }
    }
    cout << (s == t ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}