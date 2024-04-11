#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    bool ok = false;
    for (int k = 30; k >= 0; --k) {
      int one = 0;
      int zero = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] & (1 << k)) {
          ++one;
        } else {
          ++zero;
        }
      }

      if (one % 2 == 0) {
        continue;
      }

      if (one % 4 == 1) {
        cout << "WIN\n";
      } else if (zero % 2 == 0) {
        cout << "LOSE\n";
      } else {
        cout << "WIN\n";
      }
      ok = true;
      break;
    }

    if (!ok) {
      cout << "DRAW\n";
    }
  }
}