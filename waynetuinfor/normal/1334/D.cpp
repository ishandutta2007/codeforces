#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    int64_t l, r;
    cin >> n >> l >> r;
    l--;
    int64_t last = 0;
    for (int i = 1; i <= n; ++i) {
      int64_t tl = last;
      int64_t tr = tl + 2 * (n - i);
      int64_t kl = max(tl, l);
      int64_t kr = min(tr, r);
      last = tr;
      if (kl >= kr) continue;
      int pl = kl - tl;
      int pr = kr - kl;
      for (int64_t j = kl; j < kr; ++j) {
        if (j & 1) cout << ((j + 1) - tl) / 2 + i << " ";
        else cout << i << " ";
      }
    }
    if (r == 1LL * n * (n - 1) + 1) cout << 1;
    cout << "\n";
  }
}