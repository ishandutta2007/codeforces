/**
 *    author:  tourist
 *    created: 16.08.2020 17:44:47       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        cout << " ";
      }
      if (i % 2 == 0) {
        cout << 0;
      } else {
        cout << (1LL << (i + j - 1));
      }
    }
    cout << endl;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long x;
    cin >> x;
    int i = 0;
    int j = 0;
    cout << 1 << " " << 1 << endl;
    while (i < n - 1 || j < n - 1) {
      int r = 0;
      if (x & (1LL << (i + j))) {
        r = 1;
      }
      if (i % 2 != r) {
        i += 1;
      } else {
        j += 1;
      }
      cout << i + 1 << " " << j + 1 << endl;
    }
  }
  return 0;
}