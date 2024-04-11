/**
 *    author:  wxhtzdy
 *    created: 07.06.2022 20:40:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a = n / 3;
    int b = n / 3 + 1;
    int c = n / 3 - 1;
    if (n % 3 == 1) {
      b++;
    } else if (n % 3 == 2) {
      a++;
      b++;
    }
    cout << a << " " << b << " " << c << '\n';
  }                                                                    
  return 0;
}