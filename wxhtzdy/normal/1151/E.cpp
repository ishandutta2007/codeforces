/**
 *    author:  milos
 *    created: 25.02.2021 10:13:41       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Solve = [&](long long x, long long y) {
    if (x > y) {
      return (x - y) * (n - x + 1);
    } else {
      return (y - x) * x;  
    }
  };
  long long ans = Solve(a[0], 0);
  for (int i = 1; i < n; i++) {
    ans += Solve(a[i], a[i - 1]);
  }
  cout << ans << '\n';
  return 0;
}