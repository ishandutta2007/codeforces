#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int x[N], y[N], l[N], r[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      l[i] = x[i], r[i] = y[i];
    }
    sort(x, x + n);
    sort(y, y + n);

    int ans = n;
    for (int i = 0; i < n; ++i) {
      int low = lower_bound(y, y + n, l[i]) - y;
      int high = n - (upper_bound(x, x + n, r[i]) - x);
      ans = min(ans, low + high);
    }
    cout << ans << "\n";
  }
}