/**
 *    author:  tourist
 *    created: 24.11.2019 11:04:23       
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
    string t = "";
    for (int i = 0; i < k; i++) {
      t += "()";
    }
    while (t.size() < s.size()) {
      t = t.substr(0, t.size() - 1) + "())";
    }
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (s[j] == t[i]) {
          cout << i + 1 << " " << j + 1 << '\n';
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
    }
  }
  return 0;
}