/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 16:40:57
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
    char c;
    cin >> c;
    string s;
    cin >> s;
    s = s + s;       
    int ans = 0;
    int lst = 1e9;
    n = n + n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'g') {
        lst = i;
      }
      if (s[i] == c && lst != 1e9) {
        ans = max(ans, lst - i);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}