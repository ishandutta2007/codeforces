#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;

    int d = x % 10;
    int c = 0;

    while (x > 0) {
      x /= 10;
      ++c;
    }

    cout << c * (c + 1) / 2 + 10 * (d - 1) << "\n";
  }
}