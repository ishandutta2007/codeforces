#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = (1 << 20) + 10;
int mx[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  for (int l = 0; l < SZ(s); l++) {
    int mask = 0;
    for (int r = l; r < SZ(s); r++) {
      int cur = s[r] - 'a';
      if ((mask >> cur) & 1) {
        break;
      }
      mask |= 1 << cur;
      mx[mask] = __builtin_popcount(mask);
    }
  }
  for (int i = 1; i < (1 << 20); i++) {
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1) {
        mx[i] = max(mx[i], mx[i ^ (1 << j)]);
      }
    }
  }
  int ans = 0, all = (1 << 20) - 1;
  for (int i = 0; i < (1 << 20); i++) {
    ans = max(ans, mx[i] + mx[all ^ i]);
  }
  cout << ans << '\n';
}