#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int c1, c2, c3; cin >> c1 >> c2 >> c3;
    int a[5];
    for(int i=0;i<5;i++) cin >> a[i];
    c1-=a[0];
    c2-=a[1];
    c3-=a[2];
    if(c1 < 0 || c2 < 0 || c3 < 0) {
      cout << "No" << "\n";
    }
    else {
      int x = min(c1, a[3]);
      c1-=x, a[3]-=x;
      int y = min(c2, a[4]);
      c2-=y, a[4]-=y;
      c3-=(a[3] + a[4]);
      if(c1 < 0 || c2 < 0 || c3 < 0) {
        cout << "No" << "\n";
      }
      else {
        cout << "Yes" << "\n";
      }
    }
  }
}