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

vector < vector<int> > g, gr;
vector<int> used;
vector<int> order, component;

void dfs1 (int v) {
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i)
    if (!used[ g[v][i] ])
      dfs1 (g[v][i]);
  order.push_back (v);
}

void dfs2 (int v) {
  used[v] = true;
  component.push_back (v);
  for (size_t i=0; i<gr[v].size(); ++i)
    if (!used[ gr[v][i] ])
      dfs2 (gr[v][i]);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  g.resize(n); gr.resize(n);
  vi u(n), nx(n);
  for (int i = 0; i < n; ++i) {
    cin >> u[i];
    nx[i] = (u[i] + 1) % h;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (nx[a] == u[b]) {
      g[a].push_back(b);
      gr[b].push_back(a);
    }
    if (nx[b] == u[a]) {
      gr[a].push_back(b);
      g[b].push_back(a);
    }
  }

  used.assign (n, false);
  for (int i=0; i<n; ++i)
    if (!used[i])
      dfs1 (i);
  used.assign (n, false);
  vi tm(n, -1);
  vi best(n);
  for (int i = 0; i < n; ++i) best[i] = i;
  for (int i=0; i<n; ++i) {
    int v = order[n-1-i];
    if (!used[v]) {
      component.clear();
      dfs2 (v);
      for (int i : component) tm[i] = v;
      bool ok = 1;
      for (int i : component) {
        for (int u : g[i]) if (tm[u] != v) ok = 0;
      }
      if (ok && component.size() < best.size()) best = component;
    }
  }

  cout << best.size() << endl;
  for (int i : best) cout << i + 1 << ' ';
  cout << endl;

  return 0;
}