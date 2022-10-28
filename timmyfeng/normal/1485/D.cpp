#include <bits/stdc++.h>
using namespace std;

int multiple[16 + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int lcm = 1;
  for (int i = 1; i <= 16; ++i) {
    lcm *= i / __gcd(lcm, i);
  }

  for (int i = 1; i <= 16; ++i) {
    for (int j = 1; i * j <= 1000000; ++j) {
      int d = abs(i * j - lcm);
      bool ok = false;
      for (int k = 1; k * k * k * k <= d; ++k) {
        if (k * k * k * k == d) {
          ok = true;
        }
      }

      if (ok) {
        multiple[i] = i * j;
        break;
      }
    }
  }

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      if ((i + j) % 2 == 0) {
        cout << lcm << " ";
      } else {
        cout << multiple[a] << " ";
      }
    }
    cout << "\n";
  }
}