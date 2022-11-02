#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

void dfs(int v, const vvi& g, vi& w) {
  if (w[v]) return;
  w[v] = 1;
  for (int nv : g[v]) dfs(nv, g, w);
}

int TIME = 1;

void dfs0(int v, const vvi& g, vii& out) {
  if (out[v].first) return;
  out[v].first = TIME;
  for (int nv : g[v]) dfs0(nv, g, out);
  out[v].first = TIME++;
}

bool bad(vvi g) {
  vii out(g.size());
  for (int i = 0; i < g.size(); ++i) {
    dfs0(i, g, out);
    out[i].second = i;
  }
  sort(out.rbegin(), out.rend());
  vi pos(g.size());
  for (int i = 0; i < out.size(); ++i) pos[out[i].second] = i;
  for (int i = 0; i < out.size(); ++i) {
    for (int nv : g[out[i].second]) if (pos[nv] < i) return true;
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vvi> g(2, vvi(n));
  vvi w(2, vi(n));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[0][a].push_back(b);
    g[1][b].push_back(a);
  }
  string res(n, 'E');
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (!w[0][i] && !w[1][i]) {
      res[i] = 'A';
      ++c;
    }
    dfs(i, g[0], w[0]);
    dfs(i, g[1], w[1]);
  }
  if (bad(g[0])) c = -1;
  cout << c << endl;
  if (c != -1) cout << res << endl;
  return 0;
}