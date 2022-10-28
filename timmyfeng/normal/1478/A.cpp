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

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a != x) {
        y = 0, x = a;
      }
      z = max(z, ++y);
    }

    cout << z << "\n";
  }
}