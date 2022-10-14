/**
 *    author:  wxhtzdy
 *    created: 24.01.2022 17:49:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int k, n, s, p;
  cin >> n >> k >> s >> p;
  int need = (k + s - 1) / s;
  int ans = (need * n + p - 1) / p;
  cout << ans << '\n';
  return 0;
}