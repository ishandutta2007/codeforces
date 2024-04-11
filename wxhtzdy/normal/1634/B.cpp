/**
 *    author:  wxhtzdy
 *    created: 06.02.2022 22:55:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    long long y;
    cin >> y;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i] % 2;
    }
    if ((x + s) % 2 == y % 2) {
      cout << "Alice" << '\n';
    } else {
      cout << "Bob" << '\n';
    }
  }                                                                    
  return 0;
}