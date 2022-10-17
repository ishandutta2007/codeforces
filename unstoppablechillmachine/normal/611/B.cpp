#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int l, r;
  cin >> l >> r;
  int ans = 0;
  for (int mx_bit = 1; mx_bit <= 61; mx_bit++) {
    int cur = (1ll << (mx_bit + 1)) - 1;
    for (int nl_bit = mx_bit - 1; nl_bit >= 0; nl_bit--) {
      int vl = cur ^ (1ll << nl_bit);
      if (vl >= l && vl <= r) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}