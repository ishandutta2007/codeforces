#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vi f(const vvi& g, int s) {
  vi d(g.size(), 1e9);
  d[s] = 0;
  vi q(1, s);
  int it = 0;
  while (it < q.size()) {
    int v = q[it];
    ++it;
    for (int nv : g[v]) if (d[nv] > d[v] + 1) {
      d[nv] = d[v] + 1;
      q.push_back(nv);
    }
  }
  return d;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vi a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    --a[i];
  }
  vvi g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi d1 = f(g, 0);
  vi d2 = f(g, n - 1);
  int D = d1[n - 1];
  vii ts(k);
  set<pii> w;
  for (int i = 0; i < k; ++i) {
    ts[i] = pii(d1[a[i]], a[i]);
    w.insert(pii(d2[a[i]], a[i]));
  }
  sort(ts.begin(), ts.end());
  int res = 0;
  for (pii p : ts) {
    int v = p.second;
    w.erase(pii(d2[v], v));
    if (w.empty()) break;
    auto it = w.end(); --it;
    res = max(res, min(D, d1[v] + 1 + it->first));
  }
  cout << res << endl;
  return 0;
}