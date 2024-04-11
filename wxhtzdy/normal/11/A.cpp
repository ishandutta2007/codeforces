/**
 *    author:  milos
 *    created: 23.03.2021 13:42:25       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      int j = (a[i - 1] - a[i]) / d + 1;
      ans += j;
      a[i] += j * d;  
    }
  }
  cout << ans << '\n';
  return 0;
}