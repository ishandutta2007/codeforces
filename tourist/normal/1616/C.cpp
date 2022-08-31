/**
 *    author:  tourist
 *    created: 29.12.2021 18:44:05       
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
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int A = a[i] - a[j];
        int B = j - i;
        int C = -A * i - B * a[i];
        int cur = 0;
        for (int k = 0; k < n; k++) {
          int num = (-A * k - C);
          int den = B;
          if (num != den * a[k]) {
            cur += 1;
          }
        }
        ans = min(ans, cur);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}