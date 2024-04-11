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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> cnt(n + 1), cnt2(n + 1);
    for (int i = 0; i < l; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    for (int i = 0; i < r; i++) {
      int x;
      cin >> x;
      cnt2[x]++;
    }
    int pars = 0, ans = 1e9, can_l = 0, can_r = 0;
    for (int i = 1; i <= n; i++) {
      int k = min(cnt[i], cnt2[i]);
      cnt[i] -= k;
      cnt2[i] -= k;
      pars += k;
      can_l += cnt[i] / 2;
      can_r += cnt2[i] / 2;
    }
    for (int take_l = 0; take_l <= can_l; take_l++) {
      int ost_l = l - pars - 2 * take_l;
      int sum = take_l;
      int ost_r = r - pars;
      if (ost_r > ost_l) {
        sum += min((ost_r - ost_l) / 2, can_r);
        ost_r -= 2 * min((ost_r - ost_l) / 2, can_r);
      }
      //cout << take_l << ' ' << sum << '\n';
      sum += min(ost_l, ost_r) + abs(ost_l - ost_r);
      ans = min(ans, sum);
    }
    cout << ans << '\n';
  }
}