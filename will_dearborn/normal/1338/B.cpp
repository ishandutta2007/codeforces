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
vi col;

void dfs(int v, int p, int c) {
  col[v] = c;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v, 1-c);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  col.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1, 0);
  vi c(2);
  int ma = n-1;
  vi was(n);
  for (int i = 0; i < n; ++i) if (g[i].size() == 1) {
    if (was[g[i][0]]) --ma;
    was[g[i][0]] = 1;
    ++c[col[i]];
  }
  int mi = 1;
  if (c[0] && c[1]) mi = 3;
  cout << mi << ' ' << ma << endl;
  return 0;
}