/**
 *    author:  wxhtzdy
 *    created: 24.08.2022 21:20:49
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
  int pos = 0;
  while (pos < n - 1) {
    int nxt = min(n - 1, pos + k);
    while (s[nxt] == '#') {
      nxt -= 1;
    }
    if (pos == nxt) {
      cout << "NO" << '\n';
      return 0;
    }
    pos = nxt;
  }
  cout << "YES" << '\n';                                                     
  return 0;
}