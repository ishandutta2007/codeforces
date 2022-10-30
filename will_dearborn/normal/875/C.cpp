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

vvi g;
vi was, c;
bool fail = 0;

void dfs(int v) {
  if (was[v]) return;
  if (c[v] == 2) fail = 1;
  c[v] = 1;
  for (int nv : g[v]) dfs(nv);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi v(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    v[i].resize(l);
    for (int j = 0; j < l; ++j) cin >> v[i][j];
  }
  c.assign(m+1, 0);
  g.resize(m + 1);
  was.assign(m+1, 0);
  for (int i = 0; i + 1 < n; ++i) {
    bool diff = 0;
    for (int j = 0; j < min(v[i].size(), v[i+1].size()); ++j) {
      if (v[i][j] != v[i+1][j]) {
        if (v[i][j] < v[i+1][j]) {
          g[v[i+1][j]].push_back(v[i][j]);
        } else {
          if (c[v[i][j]] == 2 || c[v[i+1][j]] == 1) fail = 1;
          c[v[i][j]] = 1;
          c[v[i+1][j]] = 2;
        }
        diff = 1;
        break;
      }
    }
    if (!diff && v[i].size() > v[i+1].size()) fail = 1;
  }
  if (!fail) for (int i = 1; i <= m; ++i) if (c[i] == 1 && !was[i]) {
    dfs(i);
  }
  if (fail) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    int k = 0;
    for (int i = 0; i < c.size(); ++i) if (c[i] == 1) ++k;
    cout << k << endl;
    for (int i = 0; i < c.size(); ++i) if (c[i] == 1) cout << i << ' ';
  }
  return 0;
}