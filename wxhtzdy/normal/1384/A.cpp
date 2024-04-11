/**
 *  author: milos
 *  created: 25.09.2020 22:29:31
**/
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<string> s(n + 1);
    s[0] = "";
    for (int i = 0; i < 200; i++) {
      s[0] += 'a';
    }
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1];
      if (s[i][a[i - 1]] == 'a') {
        s[i][a[i - 1]] = 'b';  
      } else {
        s[i][a[i - 1]] = 'a';
      }
    }
    for (int i = 0; i <= n; i++) {
      cout << s[i] << '\n';
    }
  }
  return 0;
}