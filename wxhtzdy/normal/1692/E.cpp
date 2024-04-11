/**
 *    author:  wxhtzdy
 *    created: 14.06.2022 16:55:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sum = 0;
    const int inf = (int) 1e9;
    vector<int> ops(n + 1, inf);
    ops[0] = 0;
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i];
      ops[sum] = min(ops[sum], n - i);
    } 
    if (sum < s) {
      cout << -1 << '\n';
      continue;
    }
    int ans = ops[sum - s];
    int tot = sum;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (tot - sum < s) {
        break;
      }
      ans = min(ans, i + 1 + ops[tot - sum - s]);    
    }
    cout << ans << '\n';
  }
  return 0;
}