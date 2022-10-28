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

    int ans = n;
    for (int i = 1; i * i <= n; ++i) {
      ans = min(ans, i + (n - 1) / i - 1);
    }

    cout << ans << "\n";
  }
}