/**
 *    author:  milos
 *    created: 04.02.2021 16:43:42       
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
    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<long long> dp(n, 0LL);   
    for (int i = 1; i < n; i++) {
      if (a[i] == b[i]) {
        dp[i] = c[i] + 1;
      } else {
        dp[i] = max(abs(a[i] - b[i]), dp[i - 1] - abs(a[i] - b[i])) + c[i] + 1;
      }    
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';             
  }
  return 0;
}