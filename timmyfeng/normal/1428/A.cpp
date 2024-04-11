#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y2 - y1) << "\n";
    } else if (y1 == y2) {
      cout << abs(x2 - x1) << "\n";
    } else {
      cout << abs(x2 - x1) + abs(y2 - y1) + 2 << "\n";
    }
  }
}