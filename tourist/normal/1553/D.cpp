/**
 *    author:  tourist
 *    created: 22.07.2021 17:41:06       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    int i = n - 1;
    bool ok = true;
    for (int j = m - 1; j >= 0; j--) {
      while (i >= 0 && s[i] != t[j]) {
        i -= 2;
      }
      if (i < 0) {
        ok = false;
        break;
      }
      i -= 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}