/**
 *    author:  milos
 *    created: 28.01.2021 02:51:24       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int mn = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1));
  int mx = 0;    
  {         
    int x = min(a1, n / k1);
    int y = n - x * k1;
    int z = min(a2, y / k2);
    mx = max(mx, x + z);
  }
  {         
    int x = min(a2, n / k2);
    int y = n - x * k2;
    int z = min(a1, y / k1);
    mx = max(mx, x + z);
  }
  cout << mn << " " << mx << '\n';
  return 0;
}