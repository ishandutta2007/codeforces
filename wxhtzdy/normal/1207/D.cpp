#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 3e5 + 5;
const int md = 998244353;

ll f[N];
pair<ll, ll> a[N];

void calc() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] * i;
    f[i] %= md;
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  calc();
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    --a[i].first, --a[i].second;
    ++x[a[i].first], ++y[a[i].second];
  }
  sort(a.begin(), a.end());
  ll ans = f[n];
  ll nans = 1;
  for (int i = 0; i < n; i++) {
    nans *= f[x[i]];
    nans %= md;
  }
  ans -= nans;
  if (ans < 0) ans += md;
  nans = 1;
  for (int i = 0; i < n; i++) {
    nans *= f[y[i]];
    nans %= md;
  }
  ans -= nans;
  if (ans < 0) ans += md;
  int mx = -1;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (mx > a[i].second) {
      ok = false;
      break;
    } else mx = a[i].second;
  }
  if (ok) {
    nans = 1;
    for (int i = 0, j = 0; i < n; i++) {
      if (i == n - 1 || a[i] != a[i + 1]) {
        nans *= f[i - j + 1];
        nans %= md;
        j = i + 1;
      }
    }
    ans += nans;
    ans %= md;
  }
  cout << ans << '\n';
}