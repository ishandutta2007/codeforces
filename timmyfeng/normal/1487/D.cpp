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

    long long l = 0, r = (n - 1) / 2;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      if ((2 * m + 1) * (2 * m + 1) / 2 < n) {
        l = m;
      } else {
        r = m - 1;
      }
    }

    cout << r << "\n";
  }
}