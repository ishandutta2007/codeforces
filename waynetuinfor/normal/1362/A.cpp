#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    while (a % 2 == 0) {
      a >>= 1;
      x++;
    }
    while (b % 2 == 0) {
      b >>= 1;
      y++;
    }
    if (a != b) {
      cout << "-1\n";
    } else {
      cout << (abs(x - y) + 2) / 3 << "\n";
    }
  }
  return 0;
}