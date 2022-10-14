/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 16:33:35
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
    int s = (n % 2) + (m % 2);
    cout << (s == 1 ? "Burenka" : "Tonya") << '\n';
  }                                                                    
  return 0;
}