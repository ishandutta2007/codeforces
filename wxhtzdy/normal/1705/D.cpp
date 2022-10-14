/**
 *    author:  wxhtzdy
 *    created: 18.07.2022 20:41:29
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
    string s, t;
    cin >> s >> t;
    if (s == t) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> xs;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        xs.push_back(i);
      }
    }
    vector<int> ys;
    for (int i = 0; i < n - 1; i++) {
      if (t[i] != t[i + 1]) {
        ys.push_back(i);
      }
    }
    if (s[0] != t[0] || s[n - 1] != t[n - 1] || (int) xs.size() != (int) ys.size()) {
      cout << -1 << '\n';
      continue;
    }
    long long ans = 0;
    for (int i = 0; i < (int) xs.size(); i++) {
      ans += abs(xs[i] - ys[i]);
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}