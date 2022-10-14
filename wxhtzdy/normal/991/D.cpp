/**
 *  author: milos
 *  created: 06.01.2021 17:40:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> s(2);
  cin >> s[0] >> s[1];
  int n = (int) s[0].length(), ans = 0, was = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    if (s[0][i] == '0') sum += 1;
    if (s[1][i] == '0') sum += 1;
    if (sum + was >= 3) {
      ans += 1;
      was += sum;
      was -= 3;
    } else {
      was = sum;
    }
  }
  cout << ans << '\n';
  return 0;
}