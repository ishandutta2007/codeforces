/**
 *    author:  tourist
 *    created: 21.12.2019 14:05:03       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  cout << n << '\n';
  string t = s.substr(0, k);
  for (int i = k; i < n; i++) {
    t += t[i - k];
  }
  if (t >= s) {
    cout << t << '\n';
  } else {
    for (int i = k - 1; i >= 0; i--) {
      if (t[i] == '9') {
        t[i] = '0';
      } else {
        ++t[i];
        break;
      }
    }
    for (int i = k; i < n; i++) {
      t[i] = t[i - k];
    }
    cout << t << '\n';
  }
  return 0;
}