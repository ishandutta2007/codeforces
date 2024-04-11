#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (j - i <= (n - 1) / 2) {
          cout << -1 << " ";
        } else if (2 * (j - i) == n) {
          cout << 0 << " ";
        } else {
          cout << 1 << " ";
        }
      }
    }

    cout << "\n";
  }
}