/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 21:01:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + (s[i] == 'W' ? 1 : 0);
    }
    int ans = n;
    for (int i = 0; i + k <= n; i++) {
      ans = min(ans, pref[i + k] - pref[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}