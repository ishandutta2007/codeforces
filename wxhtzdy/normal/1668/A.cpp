#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
      cout << 0 << '\n';
    } else {
      if ((n == 1 && m == 2) || (n == 2 && m == 1)) {
        cout << 1 << '\n';
      } else if (n == 1 || m == 1) {
        cout << -1 << '\n';
      } else {
        cout << n + m - 2 + ((max(n, m) - min(n, m)) / 2) * 2 << '\n';
      }
    }
  }                                                                    
  return 0;
}