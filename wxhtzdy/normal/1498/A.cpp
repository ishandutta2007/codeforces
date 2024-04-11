/**
 *    author:  milos
 *    created: 29.03.2021 16:35:37       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  auto Sum = [&](long long n) {
    long long sum = 0;
    while (n > 0LL) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  };
  while (tt--) {
    long long n;
    cin >> n;
    while (__gcd(n, Sum(n)) == 1) {
      n++;
    }
    cout << n << '\n';
  }
  return 0;
}