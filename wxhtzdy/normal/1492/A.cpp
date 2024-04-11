/**
 *    author:  milos
 *    created: 23.02.2021 10:05:32       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) { 
    long long a, b, c, p;
    cin >> p >> a >> b >> c;
    long long ans = (a - p % a) % a;
    ans = min(ans, (b - p % b) % b);
    ans = min(ans, (c - p % c) % c);
    cout << ans << '\n';
  }
  return 0;
}