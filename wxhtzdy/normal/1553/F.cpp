#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct fenwick {
  int n;
  vector<ll> a;
  fenwick(int _n) {
    n = _n;
    a.resize(n);
  }
  void update(int x, int y) {
    for (; x < n; x += x & -x) a[x] += y;
  }
  ll get(int x) {
    ll res = 0;
    for (; x; x -= x & -x) res += a[x];
    return res;
  }
  int get(int x, int y) {
    return get(y) - get(x - 1);
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int MX = 3e5 + 5;
  fenwick x(MX), y(MX);
  ll ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * (ll) i - x.get(a[i]) + sum;
    sum += a[i];
    for (int j = a[i]; j < MX; j += a[i]) {
      int cnt = y.get(j, min(MX - 1, j + (int) a[i] - 1));
      ans -= (ll) cnt * j;
      x.update(j, a[i]);
    }
    y.update(a[i], 1);
    cout << ans << " ";
  }
}