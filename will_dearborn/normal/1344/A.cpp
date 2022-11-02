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
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vi a(n), w(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      w[(i + a[i] % n + n) % n]++;
    }
    bool fail = 0;
    for (int i : w) if (i > 1) fail = 1;
    if (fail) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}