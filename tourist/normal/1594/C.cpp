/**
 *    author:  tourist
 *    created: 08.10.2021 18:29:54       
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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (s[i] == c);
    }
    if (cnt == n) {
      cout << 0 << '\n';
      continue;
    }
    bool found = false;
    for (int d = 1; d <= n; d++) {
      int cc = 0;
      for (int i = d; i <= n; i += d) {
        cc += (s[i - 1] != c);
      }
      if (cc == 0) {
        cout << 1 << '\n';
        cout << d << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << 2 << '\n';
      cout << n - 1 << " " << n << '\n';
    }
  }
  return 0;
}