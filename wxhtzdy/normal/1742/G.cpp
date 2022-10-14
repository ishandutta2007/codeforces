/**
 *    author:  wxhtzdy
 *    created: 13.10.2022 17:03:01
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
    vector<int> ans;
    int res = 0;
    vector<bool> taken(n);  
    for (int b = 0; b < 31; b++) {
      int idx = -1;
      int mx = -1;
      for (int i = 0; i < n; i++) {
        if (taken[i]) {
          continue;
        }
        int new_res = (res | (a[i]));
        if (new_res > mx) {
          mx = new_res;
          idx = i;
        }
      }
      if (idx == -1) {
        break;
      }
      res = mx;
      ans.push_back(a[idx]);
      taken[idx] = true;
    }
    for (int i = 0; i < n; i++) {
      if (!taken[i]) {
        ans.push_back(a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }                                                                     
  return 0;
}