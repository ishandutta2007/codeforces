/**
 *  author: milos
 *  created: 10.01.2021 00:42:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = 0;
  for (int i = 5; i < n; i++) {
    if (n % i == 0 && n / i >= 5) {
      m = i;
      break;  
    }
  }
  if (m == 0) {
    cout << -1 << '\n';
    return 0;
  }
  string s = "aeiou";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n / m; j++) {
      cout << s[(i + j) % 5];
    }
  }
  cout << '\n';
  return 0;
}