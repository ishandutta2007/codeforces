/**
 *    author: m371
 *    created: 10.10.2021 11:15:29
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
    string s, t;
    cin >> s >> t;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] == '1') {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}