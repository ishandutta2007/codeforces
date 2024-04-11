#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x, y;
  cin >> n >> m >> x >> y;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << x << " " << y << "\n";
      if (j < m - 1) {
        y = y % m + 1;
      }
    }
    x = x % n + 1;
  }
}