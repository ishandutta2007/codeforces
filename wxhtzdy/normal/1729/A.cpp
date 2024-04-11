/**
 *    author:  wxhtzdy
 *    created: 12.09.2022 16:34:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long x = abs(a - 1);
    long long y = abs(b - c) + abs(c - 1);
    cout << ((x == y ? 3 : (x < y ? 1 : 2))) << '\n';
  }                                                                    
  return 0;
}