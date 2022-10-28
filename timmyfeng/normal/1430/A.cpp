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

    if (n == 1 || n == 2 || n == 4) {
      cout << -1 << "\n";
    } else if (n % 3 == 2) {
      cout << (n - 5) / 3 << " " << 1 << " " << 0 << "\n";
    } else if (n % 3 == 0) {
      cout << n / 3 << " " << 0 << " " << 0 << "\n";
    } else {
      cout << (n - 7) / 3 << " " << 0 << " " << 1 << "\n";
    }
  }
}