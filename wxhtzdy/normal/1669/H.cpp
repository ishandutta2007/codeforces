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
    vector<int> cnt(31);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 31; j++) {
        if (x >> j & 1) {
          cnt[j] += 1;
        }
      }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int x = n - cnt[i];
      if (k >= x) {
        ans += (1 << i);
        k -= x;
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}