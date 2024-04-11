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

    int l = INT_MAX;
    int r = 0;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      l = min(l, a);
      if (a - l < r) {
        l = a - r;
      }

      r = a - l;
    }

    cout << (l >= 0 ? "YES" : "NO") << "\n";
  }
}