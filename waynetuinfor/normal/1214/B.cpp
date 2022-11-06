#include <bits/stdc++.h>
using namespace std;

int main() {
  int b, g, n; cin >> b >> g >> n;
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (i >= 0 && i <= b && n - i >= 0 && n - i <= g) ans++;
  }
  cout << ans << endl;
}