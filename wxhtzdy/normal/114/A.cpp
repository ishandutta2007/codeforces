/**
 *  author: milos
 *  created: 13.12.2020 17:38:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long l = n, cnt = 0;
  while (l < k) l *= n, cnt++;
  if (l == k) cout << "YES" << '\n' << cnt << '\n';
  else cout << "NO" << '\n';  
  return 0;
}