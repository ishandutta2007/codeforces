/**
 *    author:  tourist
 *    created: 24.11.2020 20:55:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int x : {100, 20, 10, 5, 1}) {
    ans += n / x;
    n %= x;
  }
  cout << ans << '\n';
  return 0;
}