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
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int lim = 1, cnt = 1;
    while (lim <= n) {
      lim *= 2;
      cnt++;
    }
    vector<pair<int, int>> mx(lim, make_pair(-1, -1));
    auto relax = [](pair<int, int> &kek, int val) {
      if (val > kek.F) {
        kek.S = kek.F;
        kek.F = val;
      } else if (val > kek.S) {
        kek.S = val;
      }
    };
    auto merge = [&](pair<int, int> &kek, pair<int, int> val) {
      relax(kek, val.F);
      relax(kek, val.S);
    };
    for (int i = 0; i < n; i++) {
      relax(mx[a[i]], i + 1);
    }
    for (int bit = 0; bit < cnt; bit++) {
      for (int mask = 0; mask < lim; mask++) {
        if ((mask >> bit) & 1) {
          merge(mx[mask], mx[mask ^ (1 << bit)]);
        }
      }
    }
    int ans = -1e9;
    for (int i = 0; i < lim; i++) {
      if (mx[i].F != -1 && mx[i].S != -1) {
        ans = max(ans, mx[i].F * mx[i].S - i * k);
      }
    }
    cout << ans << '\n';
  }
}