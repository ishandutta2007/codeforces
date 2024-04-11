/**
 *    author:  wxhtzdy
 *    created: 19.09.2022 21:02:20
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
    int ans = n + 1;
    for (int i = 0; i + 1 < 2 * n; i++) {
      if (s[i] == '(' && s[i + 1] == ')') {
        ans -= 1;
      }
    }
    cout << ans << '\n';
  }                                                                      
  return 0;
}