#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int b, g, n;
  cin >> b >> g >> n;

  int ans = 0;
  for (int i = 0; i <= b; ++i) {
    ans += (n - i >= 0 && n - i <= g);
  }
  cout << ans << "\n";
}