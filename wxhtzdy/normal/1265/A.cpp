/**
 *    author:  milos
 *    created: 19.04.2021 08:38:48       
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
    int n = (int) s.size();
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != '?' && s[i] == s[i + 1]) {
        ok = false;  
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }          
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        vector<int> cnt(3);
        if (i > 0 && s[i - 1] != '?') cnt[s[i - 1] - 'a'] += 1;
        if (i < n - 1 && s[i + 1] != '?') cnt[s[i + 1] - 'a'] += 1;
        for (int j = 0; j < 3; j++) {
          if (cnt[j] == 0) {
            s[i] = (char) (j + 'a');
          }
        }
      }
    }
    cout << s << '\n';
  }
  return 0;
}