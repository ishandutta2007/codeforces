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
  ll n;
  cin >> n;
  for (ll p = 2; p * p <= n; ++p) if (n % p == 0) {
    while (n % p == 0) n /= p;
    if (n == 1) {
      cout << p << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }
  cout << n << endl;
  return 0;
}