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
  int n;
  cin >> n;
  vvl a(n, vl(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n, k = (i + 2) % n;
    ll x2 = a[i][j] * a[i][k] / a[k][j];
    ll t = sqrt(x2);
    while (t * t > x2) --t;
    while (t * t < x2) ++t;
    cout << t << ' ';
  }
  cout << endl;
  return 0;
}