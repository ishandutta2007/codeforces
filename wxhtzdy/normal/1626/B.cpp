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
    int n = s.size(), pos = -1;
    for (int i = 0; i + 1 < n; i++) {
      int sum = (s[i] - '0') + (s[i + 1] - '0');
      if (sum >= 10) {
        pos = i;
      }
    }
    if (pos == -1) {
      pos = 0;
    }
    for (int i = 0; i < n; i++) {
      if (i == pos) {
        cout << (s[i] - '0') + (s[i + 1] - '0');
        i += 1;
      } else {
        cout << s[i];
      }
    }
    cout << '\n';
  }
  return 0;
}