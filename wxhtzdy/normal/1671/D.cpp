/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 13:31:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                             
    long long s = 0;
    for (int i = 0; i + 1 < n; i++) {
      s += abs(a[i] - a[i + 1]);
    }
    long long ans = min({a[0] - 1, abs(a[0] - x), a[n - 1] - 1, abs(a[n - 1] - x)}) + x - 1 + s;
    for (int i = 0; i + 1 < n; i++) {
      ans = min(ans, a[i] - 1 + x - 1 + abs(a[i + 1] - x) + s - abs(a[i] - a[i + 1]));  
      ans = min(ans, abs(a[i] - x) + x - 1 + a[i + 1] - 1 + s - abs(a[i] - a[i + 1]));  
    }
    const long long inf = 1e15;
    long long mn = a[0] - 1;
    for (int i = 0; i < n; i++) {
      if (i != n - 1) {
        ans = min(ans, s - abs(a[i] - a[i + 1]) + abs(a[i] - x) + abs(a[i + 1] - x) + mn);
        mn = min(mn, -abs(a[i] - a[i + 1]) + a[i] - 1 + a[i + 1] - 1);
      }
    }
    ans = min(ans, mn + abs(a[n - 1] - x) + s);         
    mn = inf;
    for (int i = n - 1; i >= 0; i--) {
      if (i != n - 1) {
        ans = min(ans, s - abs(a[i] - a[i + 1]) + abs(a[i] - x) + abs(a[i + 1] - x) + mn);
        mn = min(mn, -abs(a[i] - a[i + 1]) + a[i] - 1 + a[i + 1] - 1);
      } else {
        mn = a[i] - 1;
      }
    }
    ans = min(ans, mn + abs(a[0] - x) + s);
    cout << ans << '\n';
  }                                                                    
  return 0;
}