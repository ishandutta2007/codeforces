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
  int n,q;
  cin >> n >> q;
  int bad = 0;
  vvi v(2, vi(n));
  for (int t = 0; t < q; ++t) {
    int r, c;
    cin >> r >> c;
    --r; --c;
    for (int j = c - 1; j <= c + 1; ++j) if (j >= 0 && j < n) {
      if (v[1-r][j]) {
        if (v[r][c]) --bad;
        else ++bad;
      }
    }
    v[r][c] ^= 1;
    if (bad) cout << "No\n";
    else cout << "Yes\n";
  }
  return 0;
}