/**
 *  author: milos
 *  created: 02.11.2020 15:41:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = (int) s.size(), cnt = 0, ans = 0;                
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
        ans += a;
      }  
    }
    vector<int> v;
    int fst = -1, lst = -1;
    for (int i = 0; i < n; i++) {
      if (fst == -1 && s[i] == '1') {
        fst = i;
      }
      if (s[i] == '1') {
        lst = i;
      }
    }
    if (fst == -1) {
      cout << ans << '\n';
      continue;
    }
    for (int i = fst; i <= lst; i++) {
      if (s[i] == '0') {
        cnt++;
      } else {
        if (cnt > 0) {
          v.push_back(cnt);
        }
        cnt = 0;
      }
    }
    sort(v.begin(), v.end());
    for (int c : v) {
      if (c * b <= a) {
        ans -= a;
        ans += c * b;  
      } else {
        break;
      }
    }
    cout << ans << '\n';  
  }
  return 0;
}