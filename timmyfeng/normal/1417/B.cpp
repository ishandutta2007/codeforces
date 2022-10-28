#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int half = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a * 2 < m) {
        cout << 0 << " ";
      } else if (a * 2 > m) {
        cout << 1 << " ";
      } else {
        cout << half << " ";
        half ^= 1;
      }
    }

    cout << "\n";
  }
}