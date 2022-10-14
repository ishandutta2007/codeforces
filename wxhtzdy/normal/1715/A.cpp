/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 15:33:53
**/
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
    cout << min({2 * (n + m - 2), n + m - 2 + n - 1 + 1, n + m - 2 + m - 1 + 1}) << '\n';
  }                                                                    
  return 0;
}