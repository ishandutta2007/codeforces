/**
 *    author:  tourist
 *    created: 24.12.2021 17:36:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    cout << (s % n == 0 ? 0 : 1) << '\n';
  }
  return 0;
}