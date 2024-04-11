/**
 *    author:  tourist
 *    created: 30.12.2018 17:36:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long x = 0, y = 0;
  for (int i = 0; i < 2 * n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    x += xx;
    y += yy;
  }
  cout << (x / n) << " " << (y / n) << '\n';
  return 0;
}