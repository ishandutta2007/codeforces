#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> p(n), x(m);
  vector<ll> pref(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  pref[0] = p[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + p[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  sort(all(x));

  ll ans = 0;

  auto sum = [&](int l, int r) {
    return pref[r] - (l <= 0 ? 0 : pref[l - 1]);
  };

  auto calc = [&](int pos) {
    int r = lower_bound(all(x), pos) - x.begin();
    int l = r - 1;
    int u = l < 0 ? 0 : (pos + x[l] + 1) / 2;
    int v = r >= m ? 2 * mod : (pos + x[r] + 1) / 2 - 1;
    // cout << pos << " " << l << " " << r << endl;
    // cout << u << " " << v << endl;
    if (u <= v)
      ans = max(ans, sum((u + 99) / 100, min(n - 1, v / 100)));
  };

  calc(x[0]);
  for (int i = 1; i < n; i++) {
    if (i * 100 <= x[0])
      continue;
    int j = lower_bound(all(x), i * 100) - x.begin();
    if (j < m && x[j] == i * 100)
      continue;
    j--;
    calc(min(j + 1 < m ? x[j + 1] : 2 * mod, x[j] + 2 * (i * 100 - x[j])));
  }

  cout << ans << "\n";
}