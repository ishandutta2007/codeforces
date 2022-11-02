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

const ll MAX = 1e6;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = min(MAX, res * x);
    x = min(MAX, x * x);
    n /= 2;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vi erat(100001);
  for (int i = 1; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i)
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  int n, k;
  cin >> n >> k;
  vi a(n);
  map<int, int> w;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
//    for (ll x : pw) while (a[i] % x == 0) a[i] /= x;
    ll x = a[i];
    a[i] = 1;
    ll opp = 1;
    while (x > 1) {
      int p = erat[x];
      int pw = 0;
      while (x % p == 0) {
        x /= p;
        ++pw;
      }
      pw %= k;
      if (pw) {
        a[i] *= mpow(p, pw);
        opp = min(MAX, opp * mpow(p, k - pw));
      }
    }
    res += w[opp];
    w[a[i]] += 1;
  }
  cout << res << endl;
  return 0;
}