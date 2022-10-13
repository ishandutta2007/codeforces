#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 0; tc < t; tc++) {
    int s; cin >> s;
    int x = sqrt(s);
  
    if(x * x < s) {
      cout << x + 1 << "\n";
    }
    else {
      cout << x << "\n";
    }
  }
}