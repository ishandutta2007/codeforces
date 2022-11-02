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
const int mod = 1e9 + 7;
const ll M = 1e9;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vii ts(n);
  vi t(n);
  bool fail = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    ts[i] = pii(t[i], i);
  }
  sort(ts.begin(), ts.end());
  vi w(n + 1, -1);
  for (pii p : ts) {
    int v = p.second;
    for (int nv : g[v]) {
      w[t[nv]] = v;
    }
    for (int i = 1; i < w.size(); ++i) if (w[i] != v) {
      if (i != t[v]) fail = 1;
      break;
    }
  }
  if (fail) cout << -1 << endl;
  else {
    for (pii p : ts) cout << p.second + 1 << ' ';
    cout << endl;
  }
  return 0;
}