/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 20:48:24
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] / k;
      a[i] %= k;
    }
    vector<int> cnt(k);
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    int r = k - 1;
    for (int i = 0; i < k; i++) {
      while (cnt[i] > 0 && r >= i && i + r >= k) {
        if (r > i) {
          int mn = min(cnt[i], cnt[r]);
          cnt[i] -= mn;
          cnt[r] -= mn;
          ans += mn;   
        } else {
          ans += cnt[i] / 2;
          cnt[i] = 0;
        }
        if (cnt[r] == 0) {
          r -= 1;
        }
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}