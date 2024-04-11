/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:45:20
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<int> mn(4 * n + 5);
    vector<int> mx(4 * n + 5);
    int ans = 0;
    bool fail = false;
    function<void(int, int, int)> Solve = [&](int v, int l, int r) {
      if (l == r) {
        mn[v] = p[l];
        mx[v] = p[l];
        return;    
      }    
      int mid = l + r >> 1;
      Solve(v * 2, l, mid);
      Solve(v * 2 + 1, mid + 1, r);
      mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
      mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
      if (mx[v * 2] < mn[v * 2 + 1]) {
        return;
      }
      if (mn[v * 2] > mx[v * 2 + 1]) {
        ans += 1;
        return;
      }
      fail = true;
    };
    Solve(1, 0, n - 1);
    if (fail) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }                                                                    
  return 0;
}