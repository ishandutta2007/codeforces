/**
 *  author: milos
 *  created: 31.12.2020 01:32:07
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
    int n = (int) s.size(), ans = 0;
    vector<bool> was(n, false);           
    for (int i = 0; i < n; i++) {
      bool change = false;
      for (int j : {1, 2}) {
        int x = i - j;
        if (x >= 0 && s[i] == s[x] && !was[x]) {
          change = true;
        }
      }
      ans += change;
      was[i] = change;
    }
    cout << ans << '\n';
  }
  return 0;
}