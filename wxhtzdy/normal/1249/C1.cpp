/**
 *  author: milos
 *  created: 14.12.2020 11:44:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 2e4 + 5;
  map<int, int> can;
  for (int i = 0; i < (1 << 12); i++) {
    int sum = 0;
    for (int j = 0; j < 12; j++) {
      if ((i & (1 << j)) != 0) {
        sum += pow(3, j);
      }
    }
    if (sum > 0) can[sum] = 1;
    //cout << sum << '\n';
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int n;
    cin >> n;
    while (can[n] == 0) n++;
    cout << n << '\n';
  }
  return 0;
}