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
  ll n, q;
  cin >> n >> q;
  for (int test = 0; test < q; ++test) {
    ll x;
    cin >> x;
    while (x % 2 == 0) {
      x = n + x / 2;
    }
    cout << (x + 1) / 2 << endl;
  }
  return 0;
}