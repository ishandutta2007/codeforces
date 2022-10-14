/**
 *    author:  milos
 *    created: 21.02.2021 15:53:02       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int k = i ^ j;
      if (k < i + j && k >= j && k <= n) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}