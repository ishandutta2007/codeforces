/**
 *    author:  tourist
 *    created: 16.08.2020 17:40:34       
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
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        rotate(s.begin(), s.begin() + i + 1, s.end());
        break;
      }
    }
    int ans = 0;
    int t = 0;
    for (int i = 0; i <= n; i++) {
      if (i == n || (i > 0 && s[i] != s[i - 1])) {
        if (t == n) {
          ans += (t + 2) / 3;
        } else {
          ans += t / 3;
        }
        t = 1;
      } else {
        t += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}