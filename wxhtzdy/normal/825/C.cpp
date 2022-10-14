/**
 *    author: m371
 *    created: 10.10.2021 20:39:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mx = 2 * k, ans = 0;
  for (int i = 0; i < n; i++) {
    if (mx >= a[i]) {
      mx = max(mx, a[i] * 2);
    } else {
      while (mx < a[i]) {
        mx *= 2;
        ans++;    
      }
      mx = max(mx, 2 * a[i]);
    }
  }
  cout << ans << '\n';  
  return 0;
}