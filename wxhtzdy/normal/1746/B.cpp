/**
 *    author:  wxhtzdy
 *    created: 15.10.2022 16:37:24
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }          
    int ans = 1e9;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    ans = min(cnt[0], cnt[1]);
    vector<int> L(2);
    vector<int> R(2);
    R[0] = cnt[0];
    R[1] = cnt[1];
    for (int i = 0; i < n; i++) {
      R[a[i]] -= 1;
      L[a[i]] += 1;
      ans = min(ans, L[1] + max(0, R[0] - L[1]));
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}