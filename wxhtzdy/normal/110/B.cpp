/**
 *  author: milos
 *  created: 13.12.2020 16:29:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << (char) (i % 4 + 'a');
  }
  return 0;
}