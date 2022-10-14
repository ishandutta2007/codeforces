/**
 *    author:  wxhtzdy
 *    created: 30.05.2022 23:07:16
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
    sort(a.begin(), a.end());
    int l = 0, r = (n + 1) / 2;
    vector<int> ans;
    while (ans.size() < n) {
      int x = ans.size();
      if (x & 1) {
        ans.push_back(a[r++]);
      } else {                
        ans.push_back(a[l++]);
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int x = (i - 1 + n) % n;
      int y = (i + 1) % n;
      if (ans[i] >= ans[x] && ans[i] <= ans[y]) {
        ok = false;
      }
      if (ans[i] <= ans[x] && ans[i] >= ans[y]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i : ans) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }                                                                    
  return 0;
}