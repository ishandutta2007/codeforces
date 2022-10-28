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
    if (n <= 6 + 10 + 14) {
      cout << "NO\n";
    } else {
      int d = n - 6 - 10 - 14;
      cout << "YES\n";
      if (d == 6 || d == 10 || d == 14) {
        cout << 6 << " " << 10 << " " << 15 << " " << d - 1 << "\n";
      } else {
        cout << 6 << " " << 10 << " " << 14 << " " << d << "\n";
      }
    }
  }
}