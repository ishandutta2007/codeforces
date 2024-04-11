#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<short> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

vvi g;
const int L = 12;
short lc[3005][3005][L];

void dfs(int v, vector<bool> & was) {
  if (was[v]) return;
  was[v] = 1;
  for (int nv : g[v]) {
    dfs(nv, was);
  }
}

short depth[3001][3001];
short pr[3001][3001];
vector<bool> vis;

void dfs3(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  for (int nv : g[v]) dfs3(nv);
}

void dfs2(int v0, int v, int p, vector<bool> & was, const vector<vector<bool>> & r) {
  if (was[v]) return;
  was[v] = 1;
  pr[v0][v] = p;
  if (v != p) depth[v0][v] = depth[v0][p] + 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int nv = g[v][i];
//    for (int j = 0; j < i; ++j) if (r[g[v][j]][nv]) continue;
    if (!vis[nv]) dfs2(v0, nv, v, was, r);
    dfs3(nv);
//    if (r[nv][v]) break;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
  }
  for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
  vector<vector<bool>> r(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) pr[i][j] = -1;
    dfs(i, r[i]);
  }
  vector<bool> was(n);
  for (int i = 0; i < n; ++i) {
    was.assign(n, 0);
    vis.assign(n, 0);
    dfs2(i, i, i, was, r);
    for (int j = 0; j < n; ++j) {
      lc[i][j][0] = pr[i][j];
    }
    for (int l = 1; l < L; ++l) {
      for (int j = 0; j < n; ++j) if (pr[i][j] != -1) {
        lc[i][j][l] = lc[i][lc[i][j][l-1]][l-1];
      }
    }
  }
  for (int test = 0; test < q; ++test) {
    int s, t, k;
    cin >> s >> t >> k;
    --s; --t; --k;
    if (pr[s][t] == -1 || depth[s][t] < k) cout << -1 << endl;
    else {
      int l = depth[s][t] - k;
      int cur = t;
      for (int b = 0; b < L; ++b) if (l & (1 << b)) cur = lc[s][cur][b];
      cout << cur + 1 << endl;
    }
  }
  return 0;
}