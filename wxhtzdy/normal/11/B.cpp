/**
 *    author:  milos
 *    created: 23.03.2021 13:49:50       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  n = abs(n);
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  long long sum = 0;
  for (int i = 1; i < 1e5; i++) {
    sum += i;
    if (sum >= n && sum % 2 == n % 2) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}