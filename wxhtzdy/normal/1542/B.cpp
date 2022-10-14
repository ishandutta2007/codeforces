#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 1) {
      cout << ((n - 1) % b == 0 ? "Yes" : "No") << '\n';
      continue;
    }
    long long pw = 1;
    bool ok = false;
    while (pw <= n) {
      if ((n - pw) % b == 0) {
        ok = true;
        break;
      }
      pw *= a;
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}