/**
 *  author: milos
 *  created: 15.01.2021 01:01:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long m;
  cin >> n >> m;
  long long mn = max(0LL, n - 2 * m);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if ((long long) i * (i + 1) / 2 >= m) {
      mx = n - i - 1;
      break;   
    }
  }
  if (m == 0) {
    mx = n;
  }
  cout << mn << " " << mx << '\n'; 
  return 0;
}