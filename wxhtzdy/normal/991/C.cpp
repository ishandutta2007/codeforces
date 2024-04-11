/**
 *  author: milos
 *  created: 06.01.2021 17:32:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long bot = 1, top = n, ans = n;
  auto Can = [&](long long k) {
    long long sum = 0, m = n;
    while (m > 0) {
      long long t = min(m, k);
      sum += t;
      m -= t;
      m -= m / 10;  
    }
    return sum * 2 >= n;
  };
  while (bot <= top) {
    long long mid = (bot + top) / 2;
    if (Can(mid)) {
      ans = mid;
      top = mid - 1;
    } else {
      bot = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}