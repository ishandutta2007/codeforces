/**
 *    author:  milos
 *    created: 16.02.2021 16:38:42       
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
    vector<int> ans(n, 0);
    function<void(int, int, int)> Solve = [&](int l, int r, int dep) {
      if (l < 0 || r >= n || l > r) {
        return;
      }
      if (l == r) {
        ans[l] = dep;
        return;
      }
      pair<int, int> mx = {0, 0};
      for (int i = l; i <= r; i++) {
        if (mx.first < a[i]) {
          mx.first = a[i];
          mx.second = i;  
        }
      }
      ans[mx.second] = dep;
      Solve(l, mx.second - 1, dep + 1);
      Solve(mx.second + 1, r, dep + 1);
    };
    Solve(0, n - 1, 0);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}