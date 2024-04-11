#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int prv = 0;
    int diff = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      diff += (i != 0 && a > prv);
      prv = a;
    }

    if (diff == 0) {
      cout << 1 << "\n";
    } else if (k == 1) {
      cout << -1 << "\n";
    } else {
      cout << (diff - 1) / (k - 1) + 1 << "\n";
    }
  }
}