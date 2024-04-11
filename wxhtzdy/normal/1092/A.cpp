/**
 *    author:  milos
 *    created: 23.01.2021 20:38:21       
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
      cout << (char) ('a' + (int) (i % k));
    }
    cout << '\n';
  }
  return 0;
}