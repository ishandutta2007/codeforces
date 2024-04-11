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
  int a1, b1, c1, a2, b2, c2, cost1, cost2, cost3;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> cost1 >> cost2 >> cost3;
  int ans = 1e18;
  for (int b_add = 0; b_add <= 200; b_add++) {
    for (int c_add = 0; c_add <= 200; c_add++) {
      if (b1 + b_add <= c2) {
        continue;
      }
      int cur_a1 = a1, cur_a2 = a2;
      while (cur_a2 > 0) {
        cur_a1 -= max(0ll, b2 - (c1 + c_add));
        cur_a2 -= b1 + b_add - c2;
      }
      ans = min(ans, b_add * cost2 + c_add * cost3 + max(0ll, -cur_a1 + 1) * cost1);
    }
  }
  cout << ans << '\n';
}