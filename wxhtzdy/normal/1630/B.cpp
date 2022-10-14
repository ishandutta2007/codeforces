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
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[a[i]] += 1;
    }
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i] + pref[i - 1];
    }
    int x, y;
    auto Check = [&](int d) {
      for (int i = 1; i + d <= n; i++) {
        int cnt = pref[i + d] - pref[i - 1];
        if (cnt - (n - cnt) >= k) {
          x = i;
          y = i + d;
          return true;  
        }
      }
      return false;
    };
    int low = 0, high = n, diff = n;
    while (low <= high) {
      int mid = low + high >> 1;
      if (Check(mid)) {
        diff = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    assert(Check(diff));
    cout << x << " " << y << '\n';
    vector<int> ans(1, 0);
    int nxt = 1, bal = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= x && a[i] <= y) {
        bal += 1;
      } else {
        bal -= 1;
      }
      if (nxt > k - 1) {
        break;
      }
      if (bal == nxt) {
        ans.push_back(i + 1);
        nxt += 1;
      }
    }
    ans.push_back(n);
    for (int i = 1; i < ans.size(); i++) {
      cout << ans[i - 1] + 1 << " " << ans[i] << '\n';
    }
  }                                                                    
  return 0;
}