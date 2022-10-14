/**
 *  author: milos
 *  created: 15.01.2021 03:44:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << w1 + 2 * h1 + 2 + w2 + 2 * h2 + 2 + w1 - w2  << '\n'; 
  return 0;
}