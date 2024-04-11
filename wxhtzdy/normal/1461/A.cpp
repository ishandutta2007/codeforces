/**
 *  author: milos
 *  created: 11.12.2020 15:35:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cout << (char)(i % 3 + 'a');
    }
    cout << '\n';
  }
  return 0;
}