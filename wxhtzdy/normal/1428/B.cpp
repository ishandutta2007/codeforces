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
    int a = 0, b = 0;
    bool ok1 = true, ok2 = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '>') ok1 = false;
      if (s[i] == '<') ok2 = false;
      a += s[i] == '>';
      b += s[i] == '<';
    }
    if (ok1 || ok2) {
      cout << n << '\n';
      continue;
    } else {
      if (a + b == n) {
        cout << 0 << '\n';
        continue;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' || s[(i + 1) % n] == '-') {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}