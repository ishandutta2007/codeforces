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

    bool ok = false;
    while (n--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      ok |= (b == c);
    }
    ok &= (m % 2 == 0);

    cout << (ok ? "YES" : "NO") << "\n";
  }
}