/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 16:51:57
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
    int x;
    cin >> x;
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int t = h * 60 + m;
    set<int> st;
    for (int i = 0; i < 2000; i++) {
      st.insert(t % 1440);
      t += x;
    }
    int ans = 0;
    for (int i : st) {
      h = i / 60;
      m = i % 60;
      if (h % 10 == m / 10 && h / 10 == m % 10) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}