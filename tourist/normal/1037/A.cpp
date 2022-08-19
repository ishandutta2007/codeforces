/**
 *    author:  tourist
 *    created: 02.09.2018 17:35:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x = 1;
  int ans = 0;
  while (n > 0) {
    ans++;
    if (n <= x) {
      break;
    }
    n -= x;
    x <<= 1;
  }
  cout << ans << '\n';
  return 0;
}