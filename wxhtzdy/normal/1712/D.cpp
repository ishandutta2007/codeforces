/**
 *    author:  wxhtzdy
 *    created: 17.09.2022 19:02:46
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
    auto Check = [&](int x) {
      int cnt = 0;
      auto b = a;
      for (int i = 0; i < n; i++) {
        if (a[i] * 2 < x) {
          cnt += 1;
          b[i] = 1e9;
        }
      }
      if (cnt > k) {
        return false;
      }
      int add = 2;
      for (int i = 0; i + 1 < n; i++) {
        int mn = min(b[i], b[i + 1]);
        int mx = max(b[i], b[i + 1]);
        if (mn >= x) {
          add = 0;
          break;
        } else if (mx >= x) {
          add = 1;
        }
      }
      cnt += add;
      return cnt <= k;
    };
    int low = 1, high = 1e9, ans;
    while (low <= high) {
      int mid = low + high >> 1;
      if (Check(mid)) {
        ans = mid;
        low = mid + 1;
      } else {        
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}