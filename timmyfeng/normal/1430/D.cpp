#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int extra = 0;
    for (int i = 1; i < n; ++i) {
      extra += (s[i] != s[i - 1]);
    }

    int ans = 0;
    bool parity = true;

    for (int i = 0, j = 0, k = 1; i < n; i = j) {
      k = max(k, i);
      while (k < n && s[k] != s[k - 1]) {
        ++k;
      }

      if (k == n) {
        if (parity) {
          ++ans;
        }
        parity ^= true;
      } else {
        ++ans;
        ++k;
      }

      while (j < n && s[j] == s[i]) {
        ++j;
      }
    }

    cout << ans << "\n";
  }
}