/**
 *    author:  tourist
 *    created: 06.09.2020 17:28:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] != '?' && s[i % k] == '?') {
        s[i % k] = s[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != '?' && s[i % k] != '?' && s[i] != s[i % k]) {
        ok = false;
        break;
      }
    }
    int k0 = 0, k1 = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == '0') {
        ++k0;
      }
      if (s[i] == '1') {
        ++k1;
      }
    }
    ok &= (k0 <= k / 2 && k1 <= k / 2);
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}