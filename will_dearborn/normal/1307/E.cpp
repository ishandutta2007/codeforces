#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1e9 + 7;

vi f(vi a, bool inv) {
  int n = a.size();
  vi v(n), c(n);
  if (inv) reverse(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    ++c[a[i]];
    v[i] = c[a[i]];
  }
  if (inv) reverse(v.begin(), v.end());
  return v;
}

void upd(int c1, int c2, const vi& v, bool eq, ll& ma, ll& cnt) {
  ll a = 0, b = 0, ab = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] <= c2) ++b;
    if (eq) {
      if (v[i] == c1) ++a;
      if (v[i] == c1 && v[i] <= c2) ++ab;
    } else {
      if (v[i] <= c1) ++a;
      if (v[i] <= c1 && v[i] <= c2) ++ab;
    }
  }
  if (eq && a == 0) {
    cnt = 0;
    return;
  }
  if (a == 0 && b == 0) return;
  ll two = (a * b - ab) % mod;
  ll one = (eq ? a : a + b) % mod;
  if (two > 0) {
    ma += 2;
    cnt = cnt * two % mod;
  } else {
    ++ma;
    cnt = cnt * one % mod;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    --s[i];
  }
  vvi v(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    v[a].push_back(b);
  }
  for (int i = 0; i < n; ++i) sort(v[i].begin(), v[i].end());
  vi l = f(s, 0), r = f(s, 1);
  vi was(n);
  ll ma = -1, cnt = 0;
  for (int i = 0; i <= n; ++i) {
    vi x(n), y(n);
    was.assign(n, 0);
    for (int j = i; j < n; ++j) if (!was[s[j]]) {
      was[s[j]] = 1;
      y[s[j]] = r[j];
    }
    was.assign(n, 0);
    for (int j = i - 1; j >= 0; --j) if (!was[s[j]]) {
      was[s[j]] = 1;
      x[s[j]] = l[j];
    }
    int spec = i ? s[i - 1] : -1;
    ll cur = 0, mul = 1;
    for (int j = 0; j < n; ++j) {
      upd(x[j], y[j], v[j], j == spec, cur, mul);
    }
    if (cur > ma) {
      ma = cur;
      cnt = 0;
    }
    if (cur == ma) {
      cnt = (cnt + mul) % mod;
    }
  }
  cout << ma << ' ' << (cnt % mod + mod) % mod << endl;
  return 0;
}