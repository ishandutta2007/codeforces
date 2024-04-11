#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x;
    string s;
    cin >> s >> x;
    int n = s.size();

    string ans(n, '1');
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (i >= x) {
          ans[i - x] = '0';
        }
        if (i + x < n) {
          ans[i + x] = '0';
        }
      }
    }

    string t(n, '0');
    for (int i = 0; i < n; ++i) {
      t[i] += ((i >= x && ans[i - x] == '1') || (i + x < n && ans[i + x] == '1'));
    }

    if (s == t) {
      cout << ans << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}