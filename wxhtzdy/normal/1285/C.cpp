/**
 *  author: milos
 *  created: 13.01.2021 19:55:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x;
  cin >> x;
  pair<long long, long long> ans;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      long long j = x / i;
      if (__gcd(i, j) == 1LL) {
        ans.first = i;
        ans.second = j;
      }
    }
  }
  cout << ans.first << " " << ans.second;
  return 0;
}