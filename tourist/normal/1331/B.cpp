/**
 *    author:  tourist
 *    created: 01.04.2020 18:34:16       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    while (n % i == 0) {
      cout << i;
      n /= i;
    }
  }
  return 0;
}