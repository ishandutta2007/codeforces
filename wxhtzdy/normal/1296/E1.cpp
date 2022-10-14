/**
 *    author:  milos
 *    created: 30.03.2021 20:51:57       
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
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    bool can_zero = true;
    for (int j = i - 1; j >= 0; j--) {
      if (ans[j] == 0) {
        if (s[i] < s[j]) {
          can_zero = false;
        }
        break;
      }
    }
    if (can_zero) {
      continue;
    }
    bool can_one = true;
    for (int j = i - 1; j >= 0; j--) {
      if (ans[j] == 1) {
        if (s[i] < s[j]) {
          can_one = false;
        }
        break;
      }
    }
    if (can_one) {
      ans[i] = 1;
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }
  return 0;
}