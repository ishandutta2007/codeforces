#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;

    int m = 1;
    while (h % 2 == 0) {
      h /= 2;
      m *= 2;
    }

    while (w % 2 == 0) {
      w /= 2;
      m *= 2;
    }

    cout << (m >= n ? "YES" : "NO") << "\n";
  }
}