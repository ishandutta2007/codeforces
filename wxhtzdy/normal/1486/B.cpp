/**
 *    author:  milos
 *    created: 18.02.2021 21:39:08       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;       
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    if (n == 1) {
      cout << 1 << '\n';
      continue;  
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    auto Solve = [&](vector<long long> a) {
      return a[(n + 2) / 2 - 1] - a[(n + 1) / 2 - 1] + 1;
    };
    cout << Solve(x) * Solve(y) << '\n';
  }
  return 0;
}