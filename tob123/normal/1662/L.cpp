#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

struct fenwick_tree {
  int n;
  vector<int> f;
  fenwick_tree(int n = 0) : n(n), f(n + 1) {}
  void changeValue(int i, int d) {
    for (i++; i <= n; i += i & -i)
      f[i] = max(f[i], d);
  }
  void setValue(int i, int v) {
    changeValue(i, v);
  }
  int getSum(int i) {
    int s = 0;
    for (i++; i; i -= i & -i)
      s = max(s, f[i]);
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n, v; cin >> n >> v;
  vector<ll> t(n), a(n);
  vector<pair<ll, ll>> x(n);
  for (int i = 0; i < n; i++)
    cin >> t[i];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<ll> y;
  for (int i = 0; i < n; i++) {
    x[i] = {v * t[i] - a[i], v * t[i] + a[i]};
    y.push_back(v * t[i] + a[i]);
  }
  sort(all(x));
  sort(all(y));
  y.erase(unique(all(y)), y.end());
  int ans = 0;
  fenwick_tree f(n + 1);
  for (int i = 0; i < n; i++) {
    if (x[i].st < 0 || x[i].nd < 0)
      continue;
    int j = lower_bound(all(y), x[i].nd) - y.begin();
    int v = f.getSum(j) + 1;
    ans = max(ans, v);
    f.setValue(j, v);
  }
  cout << ans << "\n";
}