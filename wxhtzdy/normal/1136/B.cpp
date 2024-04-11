/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 17:08:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, k;
  cin >> n >> k;
  int ans = 2 * n + 1;
  ans += n - 1 + min(k - 1, n - k);
  cout << ans << '\n';
  return 0;
}