#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int plus = min(z1, y2);
    z1 -= plus;
    y2 -= plus;
    int minus = max(0, y1 - x2 - y2);
    cout << 2 * (plus - minus) << "\n";
  }
}