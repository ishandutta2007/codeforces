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
  ll a, b;
  cin >> a >> b;
  ll x = 1;
  for (ll i = a + 1; i <= b && i <= a + 10; ++i) {
    x = i % 10 * x % 10;
  }
  cout << x << endl;
  return 0;
}