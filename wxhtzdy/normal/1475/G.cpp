/**
 *    author:  milos
 *    created: 26.01.2021 01:19:34       
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
    const int N = (int) 2e5 + 5;
    vector<int> dp(N, 0);
    vector<int> mx(N, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= sqrt(a[i]); j++) {
        if (a[i] % j != 0) {
          continue;
        }
        dp[i] = max(dp[i], mx[j] + 1);
        if (j * j != a[i]) {
          int l = a[i] / j;
          dp[i] = max(dp[i], mx[l] + 1);
        }
      }
      mx[a[i]] = max(mx[a[i]], dp[i]);
    }
    cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}