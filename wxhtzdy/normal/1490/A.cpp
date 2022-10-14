/**
 *    author:  milos
 *    created: 16.02.2021 16:13:02       
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
    int ans = 0;
    auto Calc = [&](int x, int y) {
      int cnt = 0;
      while (2 * x < y) {
        cnt++;
        x = 2 * x;
      }
      return cnt;
    };
    for (int i = 0; i < n - 1; i++) {
      ans += Calc(min(a[i], a[i + 1]), max(a[i], a[i + 1]));  
    }
    cout << ans << '\n';
  }
  return 0;
}