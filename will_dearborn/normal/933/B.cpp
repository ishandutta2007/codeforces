#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll k, p;
  cin >> p >> k;
  vl x;
  for (int i = 0; p; ++i) {
    ll r = p % k;
    p /= k;
    if (i % 2 == 0 || r == 0) {
      x.push_back(r);
    } else {
      x.push_back(k - r);
      ++p;
    }
  }
  cout << x.size() << endl;
  for (auto& t : x) cout << t << ' ';
  return 0;
}