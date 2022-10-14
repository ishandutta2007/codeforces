/**
 *    author:  wxhtzdy
 *    created: 16.09.2022 18:50:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  long long l = 1, r = 1e18;
  auto Count = [&](long long x) {
    long long c = 0;
    if (x >= 3) {
      c += (x - 3) / 2 + 1;
    }   
    if (x >= 8) {
      c += (x - 8) / 4 + 1;
    }
    return c;
  };
  while (l <= r) {
    long long mid = l + r >> 1;
    if (Count(mid) >= n) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << r + 1 << '\n';                                                     
  return 0;
}