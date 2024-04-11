/**
 *  author: milos
 *  created: 02.01.2021 20:57:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(10);
  for (int i = 1; i < 10; i++) {
    cin >> a[i];
  }
  bool was = false;
  for (int i = 0; i < n; i++) {
    int digit = (int) (s[i] - '0');
    if (digit <= a[digit]) {
      s[i] = (char) ('0' + a[digit]);
      if (digit != a[digit]) {
        was = true;
      }
    } else {
      if (was) {
        break;
      }  
    }
  }
  cout << s << '\n';
  return 0;
}