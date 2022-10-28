#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;

  while (k--) {
    int t1, f1, t2, f2;
    cin >> t1 >> f1 >> t2 >> f2;

    if (t1 == t2) {
      cout << abs(f1 - f2) << "\n";
    } else {
      if (f1 < a && f2 < a) {
        cout << 2 * a - f1 - f2 + abs(t1 - t2) << "\n";
      } else if (f1 > b && f2 > b) {
        cout << f1 + f2 - 2 * b + abs(t1 - t2) << "\n";
      } else {
        cout << abs(f1 - f2) + abs(t1 - t2) << "\n";
      }
    }
  }
}