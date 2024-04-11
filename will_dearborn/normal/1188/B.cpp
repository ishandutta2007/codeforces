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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, p, k;
  cin >> n >> p >> k;
  vl a(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    v[i] = ((a[i] * a[i] % p * a[i] % p * a[i] - k * a[i]) % p + p) % p;
  }
  map<ll, int> c;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += c[v[i]];
    c[v[i]]++;
  }
  cout << res << endl;
  return 0;
}