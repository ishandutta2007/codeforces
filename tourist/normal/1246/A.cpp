/**
 *    author:  tourist
 *    created: 26.10.2019 12:04:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  const int inf = (int) 1e9;
  int ans = inf;
  for (int c = 1; c <= 100000; c++) {
    int num = n - p * c;
    if (num >= c) {
      int pc = __builtin_popcount(num);
      if (pc <= c) {
        ans = c;
        break;
      }
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}