#include <bits/stdc++.h>
using namespace std;

// |ai - ai-1| <= k - 1
// 0 <= ai - hi <= k - 1
// a1 = h1, an = hn

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (auto &i : h) {
      cin >> i;
    }

    int lo = h[0], hi = h[0];
    for (int i = 1; i < n; ++i) {
      if (lo > hi) {
        break;
      }
      lo -= k - 1;
      hi += k - 1;
      lo = max(lo, h[i]);
      hi = min(hi, h[i] + k - 1);
    }

    cout << (h[n - 1] >= lo && h[n - 1] <= hi ? "YES" : "NO") << "\n";
  }
}