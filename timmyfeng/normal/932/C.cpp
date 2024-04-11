#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 0; a * i <= n; ++i) {
    if ((n - a * i) % b == 0) {
      int j = (n - a * i) / b, p = 1;

      for (int k = 0; k < i; ++k) {
        cout << p + a - 1 << " ";
        for (int l = 0; l < a - 1; ++l) {
          cout << p++ << " ";
        }
        ++p;
      }

      for (int k = 0; k < j; ++k) {
        cout << p + b - 1 << " ";
        for (int l = 0; l < b - 1; ++l) {
          cout << p++ << " ";
        }
        ++p;
      }

      cout << "\n";
      exit(0);
    }
  }

  cout << -1 << "\n";
}