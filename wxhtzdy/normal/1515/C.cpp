/**
 *    author:  milos
 *    created: 03.05.2021 09:30:23       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    vector<int> h(m); 
    for (int i = 0; i < n; i++) {
      h[i % m] += a[id[i]]; 
    }
    sort(h.begin(), h.end());
    if (h[m - 1] - h[0] <= x) {
      cout << "YES" << '\n';
      vector<int> ans(n);
      for (int i = 0; i < n; i++) {
        ans[id[i]] = i % m + 1;
      }
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}