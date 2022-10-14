/**
 *    author:  milos
 *    created: 30.03.2021 20:35:18       
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
    string s;
    cin >> s;
    int x = 0, y = 0;
    pair<int, int> ans = {-1, 2 * n + 14313};
    map<pair<int, int>, int> was, lst;
    was[make_pair(0, 0)] = 1;
    lst[make_pair(0, 0)] = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') x -= 1;
      if (s[i] == 'R') x += 1;
      if (s[i] == 'U') y += 1;
      if (s[i] == 'D') y -= 1;
      if (was[make_pair(x, y)] == 1) {
        int len = ans.second - ans.first;
        int new_len = i - lst[make_pair(x, y)];
        if (new_len < len) {
          ans.first = lst[make_pair(x, y)] + 1;
          ans.second = i + 1;
        }
      } else {
        was[make_pair(x, y)] = 1;
      }
      lst[make_pair(x, y)] = i + 1;
    }                                      
    if (ans.first == -1) {
      cout << -1 << '\n';
    } else {
      cout << ans.first << " " << ans.second << '\n';
    }
  }
  return 0;
}