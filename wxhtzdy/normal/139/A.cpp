/**
 *  author: milos
 *  created: 09.01.2021 06:56:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(7);
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  int j = 0;       
  while (n > 0) {
    n -= a[j];
    if (n <= 0) {
      cout << j + 1 << '\n';
      break;
    }
    j = (j + 1) % 7;
  }
  return 0;
}