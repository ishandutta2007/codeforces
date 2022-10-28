#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;

    if (n < 3) {
      cout << 1 << "\n";
    } else {
      cout << (n - 3) / x + 2 << "\n";
    }
  }
}