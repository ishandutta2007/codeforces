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

    bool zero = true;
    bool one = false;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      zero &= (a == x);
      one |= (a == x);
      sum += a;
    }

    if (zero) {
      cout << 0 << "\n";
    } else if (one || sum == n * x) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}