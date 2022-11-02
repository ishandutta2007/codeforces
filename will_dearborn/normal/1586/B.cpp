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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;
    cin >> n >> m;
    vi was(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      was[b - 1] = 1;
    }
    for (int i = 0; i < n; ++i) if (!was[i]) {
      for (int j = 0; j < n; ++j) if (i != j) cout << i+1 << ' ' << j+1 << '\n';
      break;
    }
  }
  return 0;
}