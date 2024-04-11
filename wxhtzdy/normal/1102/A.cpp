/**
 *  author: milos
 *  created: 08.01.2021 23:10:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 4 == 0 || n % 4 == 3) cout << 0;
  else cout << 1; 
  return 0;
}