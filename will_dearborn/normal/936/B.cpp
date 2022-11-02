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
int was[100005][2];

int dfs1(int v, int t, int pr) {
  if (was[v][t]) return 0;
  was[v][t] = pr + 1;
  if (t == 1 && g[v].empty()) return v + 1;
  for (int nv : g[v]) {
    int res = dfs1(nv, 1 - t, v);
    if (res) return res;
  }
  return 0;
}

bool dfs2(int v, int t) {
  if (was[v][t] == 1) return 1;
  was[v][t] = 1;
  for (int nv : g[v]) {
    if (dfs2(nv, 1 - t)) return true;
  }
  was[v][t] = 2;
  return 0;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int x; cin >> x;
      g[i].push_back(x - 1);
    }
  }
  int s;
  cin >> s; --s;
  int cur = dfs1(s, 0, -2);
  if (cur) {
    cout << "Win\n";
    int t = 1;
    vi res;
    while (was[cur-1][t] > 0) {
      res.push_back(cur);
      cur = was[cur-1][t];
      t = 1 - t; 
    }
    res.push_back(s + 1);
    reverse(res.begin(), res.end());
    for (int x : res) {
      cout << x << ' ';
      assert(x >= 1 && x <= n);
    }
    cout << endl;
    for (int i = 0; i + 1 < res.size(); ++i) {
      assert(find(g[res[i]-1].begin(), g[res[i]-1].end(), res[i+1]-1) != g[res[i]-1].end());
    }
    assert(res[0] == s + 1);
    assert(res.size() % 2 == 0);
    assert(g[res.back()-1].empty());
    return 0;
  }
  memset(was, 0, sizeof(was));
  if (dfs2(s, 0)) {
    cout << "Draw\n";
  } else cout << "Lose\n";
  return 0;
}