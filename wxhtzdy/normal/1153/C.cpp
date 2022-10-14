#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt_open = 0, cnt_closed = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      cnt_open += 1;
    } else {
      if (s[i] == ')') {
        cnt_closed += 1;
      }
    }
  }
  int x = n / 2 - cnt_open, y = n / 2 - cnt_closed;
  if (x < 0 || y < 0) {
    cout << ":(" << '\n';
    return 0;
  }
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (x > 0) {
        ans += '(';
        x -= 1;
      } else {
        ans += ')';
        y -= 1;
      }
    } else {
      ans += s[i];
    }
  }
  int bal = 0;
  for (int i = 0; i < n; i++) {
    bal += (ans[i] == '(' ? 1 : -1);
    if (i < n - 1 && bal <= 0) {
      cout << ":(" << '\n';
      return 0;
    }
  }
  if (bal == 0) {
    cout << ans << '\n';
  } else {
    cout << ":(" << '\n';
  }
  return 0;
}