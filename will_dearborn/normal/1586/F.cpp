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

vi getv(int x, int k) {
  vi v;
  while (x) {
    v.push_back(x % k);
    x /= k;
  }
  return v;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  int c = getv(n - 1, k).size();
  cout << c << endl;
  vvi x(n);
  for (int i = 0; i < n; ++i) {
    x[i] = getv(i, k);
    while (x[i].size() < c) x[i].push_back(0);
  }
  vvi a(n, vi(n));
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
    for (int t = c - 1; t >= 0; --t) if (x[i][t] != x[j][t]) {
      cout << t + 1 << ' ';
      a[i][j] = t;
      break;
    }
  }
//  if (k == 2 && n <= 100) for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) for (int t = j + 1; t < n; ++t) assert(a[i][j] != a[j][t]);
  cout << endl;
  return 0;
}