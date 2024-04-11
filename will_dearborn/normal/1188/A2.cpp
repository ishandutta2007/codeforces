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

int dfs(int a, int p) {
  if (g[a].size() == 1) return a;
  for (int v : g[a]) if (v != p) {
    return dfs(v, a);
  }
  return a;
}

void f(int a, int b, vi& v) {
  for (int i : g[a]) if (i != b && v.size() < 2) {
    v.push_back(dfs(i, a));
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  vvi gw(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    gw[a].push_back(w);
    gw[b].push_back(w);
  }
  bool fail = 0;
  for (int i = 0; i < n; ++i) if (g[i].size() == 2) {
    fail = 1;
  }
  if (fail) {
    cout << "NO\n";
    return 0;
  } else cout << "YES\n";
  vector<array<int, 3>> x;
  for (int a0 = 0; a0 < n; ++a0) {
    for (int i = 0; i < g[a0].size(); ++i) {
      int a = a0, b = g[a0][i], w = gw[a0][i];
      if (a > b) continue;
      if (g[b].size() == 1) swap(a, b);
      vi v1, v2;
      if (g[a].size() == 1) {
        if (g[b].size() == 1) {
          x.push_back({a + 1, b + 1, w});
        } else {
          f(b, a, v2);
          x.push_back({a + 1, v2[0] + 1, w / 2});
          x.push_back({a + 1, v2[1] + 1, w / 2});
          x.push_back({v2[1] + 1, v2[0] + 1, -w / 2});
        }
      } else {
        f(a, b, v1);
        f(b, a, v2);
        x.push_back({v1[0] + 1, v1[1] + 1, -w/2});
        x.push_back({v2[0] + 1, v2[1] + 1, -w/2});
        x.push_back({v1[0] + 1, v2[1] + 1, w/2});
        x.push_back({v2[0] + 1, v1[1] + 1, w/2});
      }
    }
  }
  cout << x.size() << endl;
  for (auto t : x) {
    cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
  }
  return 0;
}