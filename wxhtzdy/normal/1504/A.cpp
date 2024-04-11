#include <bits/stdc++.h>

using namespace std;

bool pal(string s) {
  int n = (int) s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (!pal('a' + s)) {
      cout << "YES\n" << 'a' << s << '\n';
    } else {
      if (!pal(s + 'a')) {
        cout << "YES\n" << s << 'a' << '\n';
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}