/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 15:35:15
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
    long long ans = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      int L = i;
      int R = n - i - 1;
      if (s[i] == 'L') {
        ans += L;
        a[i] = R - L;
      } else {
        ans += R;
        a[i] = L - R;
      }
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
      ans += max(0LL, a[i]);
      cout << ans << " ";
    }     
    cout << '\n';
  }                                                                      
  return 0;
}