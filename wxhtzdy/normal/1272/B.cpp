/**
 *    author:  milos
 *    created: 14.03.2021 19:37:17       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    int x = min(cnt['L'], cnt['R']);
    int y = min(cnt['U'], cnt['D']);
    if (x == 0) {
      y = min(y, 1);
    }
    if (y == 0) {
      x = min(x, 1);
    }
    cout << 2 * (x + y) << '\n';
    for (int i = 0; i < x; i++) {
      cout << 'L';
    }
    for (int i = 0; i < y; i++) {
      cout << 'U';
    }
    for (int i = 0; i < x; i++) {
      cout << 'R';
    }
    for (int i = 0; i < y; i++) {
      cout << 'D';
    }
    cout << '\n';
  }
  return 0;
}