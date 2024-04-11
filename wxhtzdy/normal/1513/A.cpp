/**
 *    author:  milos
 *    created: 11.04.2021 21:45:34       
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
    if (2 * k >= n) {
      cout << -1 << '\n';
      continue;
    }         
    vector<bool> was(n + 1, false);
    for (int i = 1; i <= k; i++) {
      cout << i << " " << n - i + 1 << " ";
      was[i] = true;
      was[n - i + 1] = true;
    }
    cout << k + 1 << " ";
    was[k + 1] = true;
    for (int i = 1; i <= n; i++) {
      if (!was[i]) {
        cout << i << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}