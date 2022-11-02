#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

ll c2(ll x) {
  return x * (x - 1) / 2;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n;
  cin >> n;
  vl a(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  ll need = 0;
  for (int i = 0; i < n; ++i) {
    ll s1 = (s - c2(n - i) + c2(i) + n - 1) / n;
    if (a[i] < s1) {
      need += s1 - a[i];
      a[i] = s1;
    } else {
      ll d = min(need, a[i] - s1);
      a[i] -= d;
      need -= d;
    }
  }
  assert(need == 0);
  for (int i = n - 1; i >= 0; --i) {
    ll s1 = (s + c2(i + 1) - c2(n - 1 - i)) / n;
    if (a[i] > s1) {
      need += a[i] - s1;
      a[i] = s1;
    } else {
      ll d = min(need, s1 - a[i]);
      a[i] += d;
      need -= d;
    }
  }
  assert(need == 0);
  assert(a.back() - a[0] <= n + 1);
  while (1) {
    bool go = 0;
    for (int i = 0; i + 1 < n; ++i) {
      ll d = (a[i + 1] - a[i]) / 2;
      if (d) go = 1;
      a[i] += d;
      a[i + 1] -= d;
    }
    if (!go) break;
    for (int i = n - 2; i >= 0; --i) {
      ll d = (a[i + 1] - a[i]) / 2;
      if (d) go = 1;
      a[i] += d;
      a[i + 1] -= d;
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  return 0;
}