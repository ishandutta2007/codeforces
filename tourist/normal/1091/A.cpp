/**
 *    author:  tourist
 *    created: 30.12.2018 17:35:22       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(b, min(a + 1, c - 1));
  cout << 3 * x << '\n';
  return 0;
}