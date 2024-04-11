#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

vvi g, gw;
int d[27][101][101];
vi ord, was;

void dfs(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int nv : g[v]) dfs(nv);
  ord.push_back(v);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  was.assign(n, 0);
  gw.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    --a; --b;
    g[a].push_back(b);
    gw[a].push_back(s[0] - 'a');
  }
  for (int i = 0; i < n; ++i) dfs(i);
  //reverse(ord.begin(), ord.end());
  //for (int v : ord) cerr << v << ' '; cerr << endl;
  for (int t = 25; t >= 0; --t) {
    for (int l = 0; l < n; ++l) for (int i1 = l; i1 >= 0; --i1) {
      int i = ord[i1];
      vi a;
      for (int it = 0; it < g[i].size(); ++it) if (gw[i][it] >= t) {
        a.push_back(it);
      }
      for (int j1 = i1 == l ? 0 : l; j1 <= l; ++j1) {
        int j = ord[j1];
        for (int it : a) {
          if (!d[gw[i][it]][j][g[i][it]]) {
            d[t][i][j] = 1; break;
          }
        }
//        if (d[t][i][j]) cerr << t << ' ' << i+1 << ' ' << j+1 << endl;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (d[0][i][j]) cout << "A";
      else cout << "B";
    }
    cout << endl;
  }
  return 0;
}