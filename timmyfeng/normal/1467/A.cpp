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
    cout << 9;
    if (n > 1) {
      cout << 8;
      for (int i = 0; i < n - 2; ++i) {
        cout << (i + 9) % 10;
      }
    }
    cout << "\n";
  }
}