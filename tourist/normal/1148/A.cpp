/**
 *    author:  tourist
 *    created: 01.06.2019 17:40:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long x = 2 * c + min(a, b + 1) + min(b, a + 1);
  cout << x << '\n';
  return 0;
}