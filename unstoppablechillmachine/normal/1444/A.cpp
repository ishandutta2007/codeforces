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
    int p, q;
    cin >> p >> q;
    if (p % q != 0) {
      cout << p << '\n';
      continue;
    }
    vector<pair<int, int>> fact;
    for (int i = 2; i * i <= q; i++) {
      int cnt = 0;
      while (q % i == 0) {
        q /= i;
        cnt++;
      }
      if (cnt) {
        fact.pb({i, cnt});
      }
    }
    if (q > 1) {
      fact.pb({q, 1});
    }
    int ans = 0;
    for (auto it : fact) {
      int cur = p, cc = 0;
      while (cur % it.F == 0) {
        cur /= it.F;
        cc++;
      }
      int need = cc - (it.S - 1);
      int cur2 = p;
      for (int i = 0; i < need; i++) {
        cur2 /= it.F;
      }
      ans = max(ans, cur2);
    }
    cout << ans << '\n';
  }
}