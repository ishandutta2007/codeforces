/**
 *    author:  milos
 *    created: 25.09.2021 12:37:20       
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
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (abs(a[i] - a[j]) <= d) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}