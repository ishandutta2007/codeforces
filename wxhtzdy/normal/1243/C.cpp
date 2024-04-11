/**
 *    author:  milos
 *    created: 28.01.2021 02:23:48       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      a.push_back(i);
      if ((long long) i * i != n) {
        a.push_back(n / i);
      }
    }
  }               
  if (a.empty()) {
    cout << n << '\n';
  } else {
    long long ans = a[0];
    for (int i = 1; i < (int) a.size(); i++) {
      ans = __gcd(ans, a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}