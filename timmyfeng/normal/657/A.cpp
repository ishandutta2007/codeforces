#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, h;
  cin >> n >> d >> h;

  if (h == d) {
    if (n == 2 || d > 1) {
      for (int i = 2; i <= 1 + h; ++i) {
        cout << i - 1 << " " << i << "\n";
      }
      for (int i = 2 + h; i <= n; ++i) {
        cout << 2 << " " << i << "\n";
      }
    } else {
      cout << -1 << "\n";
    }
  } else if (d <= h * 2) {
    for (int i = 2; i <= 1 + h; ++i) {
      cout << i - 1 << " " << i << "\n";
    }
    for (int i = 2 + h; i <= 1 + d; ++i) {
      cout << (i == 2 + h ? 1 : i - 1) << " " << i << "\n";
    }
    for (int i = 2 + d; i <= n; ++i) {
      cout << 1 << " " << i << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
}