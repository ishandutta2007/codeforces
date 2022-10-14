#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ld pi = 3.14159265359;

struct fenwick {
  vector<ld> a;
  int n;
  fenwick(int _n) {
    n = _n;
    a.resize(2 * n + 1);
  }
  void update(int x, ld y) {
    for (++x; x <= n; x += x & (-x)) {
      a[x] = max(a[x], y);
    }
  }
  ld get(int x) {
    ld ret = 0;
    for (++x; x > 0; x -= x & (-x)) {
      ret = max(ret, a[x]);
    }
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> r(n), h(n);
  vector<int> pos(n);
  vector<ll> val;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> h[i];
    val.push_back(r[i] * 1LL * r[i] * h[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < n; i++) {
    pos[i] = lower_bound(val.begin(), val.end(), r[i] * 1LL * r[i] * h[i]) - val.begin();
  }
  vector<ld> dp(n);
  fenwick fenw(n);
  for (int i = 0; i < n; i++) {
    ld mx = fenw.get(pos[i] - 1);
    dp[i] = mx + r[i] * 1LL * r[i] * pi * h[i];
    fenw.update(pos[i], dp[i]);
  }
  cout << fixed << setprecision(7) << *max_element(dp.begin(), dp.end()) << '\n';
}