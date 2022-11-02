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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vvi v(n, vi(m));
    bool fail = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (i) ++v[i][j];
      if (j) ++v[i][j];
      if (i < n - 1) ++v[i][j];
      if (j < m - 1) ++v[i][j];
      if (a[i][j] > v[i][j]) fail = 1;
    }
    if (fail) cout << "NO\n";
    else {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          cout << v[i][j] << ' ';
        }
        cout << '\n';
      }
    }
  }
  return 0;
}