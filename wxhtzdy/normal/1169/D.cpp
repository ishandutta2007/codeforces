/**
 *  author: milos
 *  created: 08.01.2021 12:31:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  long long ans = 0;
  vector<int> a(n + 1, n);
  for (int i = n - 1; i >= 0; i--) {
    a[i] = a[i + 1];
    for (int j = 1; 2 * j < a[i] - i; j++) {
      if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
        a[i] = i + 2 * j;
      }
    }
    ans += n - a[i];
  }
  cout << ans << '\n';
  return 0;
}