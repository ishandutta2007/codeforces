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
  int n;
  cin >> n;
  vi p(n), sz(n, 1);
  vvi g(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    g[p[i]].push_back(i);
  }
  for (int i = n - 1; i > 0; --i) sz[p[i]] = max(sz[p[i]], 1 + sz[i]);
  int r = 0;
  vi ord(1, 0);
  vi path;
  while (g[r].size()) {
    if (g[r].size() > 1) {
      vii ts;
      for (int v : g[r]) ts.emplace_back(sz[v], v);
      sort(ts.rbegin(), ts.rend());
      for (int j = 0; j + 1 < ts.size(); ++j) {
        int v1 = ts[j].second, v2 = ts[j + 1].second;
        path.push_back(v1);
        g[v2].push_back(v1);
        p[v1] = v2;
//        sz[v2] += sz[v1];
      }
      g[r].assign(1, ts.back().second);
    }
    r = g[r][0];
    ord.push_back(r);
  }
  assert(ord.size() == n);
  for (int x : ord) cout << x << ' ';
  cout << endl << path.size() << endl;
  reverse(path.begin(), path.end());
  for (int x : path) cout << x << ' ';
  cout << endl;
  return 0;
}