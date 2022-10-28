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
    int64_t ans = 0;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      sum += a;
      ans = max(ans, -sum);
    }
    cout << ans << "\n";
  }
}