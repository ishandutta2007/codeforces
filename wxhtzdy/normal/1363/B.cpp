/**
 *  author: milos
 *  created: 07.01.2021 21:01:40
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
    int sum = 0;
    vector<int> pref(n, 0);
    for (int i = 0; i < n; i++) {
      sum += (int) (s[i] - '0');
      pref[i] = sum;
    }
    int ans = min(sum, n - sum);
    for (int i = 0; i < n; i++) {
      int suf = sum - pref[i];
      ans = min(ans, pref[i] + (n - i - 1) - suf);
      ans = min(ans, i + 1 - pref[i] + suf);  
    }
    cout << ans << '\n';
  }
  return 0;
}