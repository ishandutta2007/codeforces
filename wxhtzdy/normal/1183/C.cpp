/**
 *    author:  milos
 *    created: 28.01.2021 10:47:08       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k > n * a) {
      cout << n << '\n';
      continue;
    }
    long long c = n * a - k;
    long long ans = (c + a - b) / (a - b);
    if (ans > n) {
      cout << -1 << '\n';
    } else {
      cout << n - ans << '\n';
    }
  }
  return 0;
}