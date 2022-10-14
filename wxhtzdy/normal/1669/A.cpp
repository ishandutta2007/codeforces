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
    int x;
    if (n <= 1399) {
      x = 4;
    } else {
      if (n <= 1599) {
        x = 3;
      } else {
        x = (n <= 1899 ? 2 : 1);
      }
    }
    cout << "Division " << x << '\n';
  }                                                                      
  return 0;
}