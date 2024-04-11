/**
 *    author:  milos
 *    created: 16.02.2021 16:04:59       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<long long> all;
  for (long long i = 1; i <= (int) 1e4; i++) {
    all.insert(i * i * i);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    bool ok = false;
    for (long long i = 1; i <= (int) 1e4; i++) {
      long long x = (long long) i * (long long) i * (long long) i;
      if (all.find(n - x) != all.end()) {
        ok = true;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}