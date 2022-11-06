#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y;
    cin >> x >> y;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x == x1 && x == x2 && a + b > 0 || y == y1 && y == y2 && c + d > 0) cout << "No\n";
    else if (x + b - a >= x1 && x + b - a <= x2 && y + d - c >= y1 && y + d - c <= y2) cout << "Yes\n";
    else cout << "No\n";
  }
}