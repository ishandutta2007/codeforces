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
    if (n == 1) {
      cout << "YES" << '\n';
    } else if (n == 2) {
      if (s[0] == s[1]) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}