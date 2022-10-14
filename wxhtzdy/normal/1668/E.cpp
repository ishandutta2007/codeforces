/**
 *    author:  tourist
 *    created: 19.04.2022 18:50:02       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    cout << "1 1" << '\n';
    return 0;
  }
  int k = 0;
  while ((k + 1) + (2 * k + 1) <= n) {
    k += 1;
  }
  cout << n - k << '\n';
  int x = n - (k + (2 * k - 1));
  for (int i = 0; i < x; i++) {
    cout << i + 1 << " " << i + 1 << '\n';
  }
  for (int i = 0; i < k - 1; i++) {
    cout << x + 1 + i << " " << x + 1 + (k - 2 - i) << '\n';
  }
  x += k - 1;
  for (int i = 0; i < k; i++) {
    cout << x + 1 + i << " " << x + 1 + (k - 1 - i) << '\n';
  }
  return 0;
}