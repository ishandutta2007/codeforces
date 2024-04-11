/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 21:46:38
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
    auto Ask = [&](int l, int r) {
      cout << "? " << l + 1 << " " << r + 1 << endl;
      int cnt = 0;
      for (int i = 0; i <= r; i++) {
        int x;
        cin >> x;
        if (x <= r + 1) {
          cnt += 1;
        }
      }
      return cnt;
    };
    int low = 0, high = n - 1, ans = 0;
    while (low <= high) {
      int mid = low + high >> 1;
      if (Ask(0, mid) % 2 == 1) {
        ans = mid;
        high = mid - 1;
      } else {        
        low = mid + 1;
      }
    }
    cout << "! " << ans + 1 << endl;
  }                                                                    
  return 0;
}