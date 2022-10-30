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
vi pr, was;

void dfs(int v, int p) {
  if (was[v]) return;
  was[v] = 1;
  pr[v] = p;
  for (int nv : g[v]) {
    dfs(nv, v);
  }
}

void getp(int v, vi& a) {
  a.clear();
  while (v != -1) {
    a.push_back(v);
    v = pr[v];
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  was.assign(n, 0);
  pr.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  int q;
  cin >> q;
  vii a(q);
  vi w(n);
  for (int i = 0; i < q; ++i) {
    cin >> a[i].first >> a[i].second;
    --a[i].first; --a[i].second;
    w[a[i].first]++;
    w[a[i].second]++;
  }
  int c = 0;
  for (int i = 0; i < n; ++i) c += w[i] % 2;
  if (c) {
    assert(c % 2 == 0);
    cout << "NO\n" << c / 2 << endl;
    return 0;
  }
  cout << "YES\n";
  vi x, y;
  for (pii p : a) {
    getp(p.first, x);
    getp(p.second, y);
    int last = -1;
    while (x.size() + y.size() && x.back() == y.back()) {
      last = x.back();
      x.pop_back();
      y.pop_back();
    }
    x.push_back(last);
    reverse(y.begin(), y.end());
    for (int t : y) x.push_back(t);
    cout << x.size() << '\n';
    for (int t : x) cout << t + 1 << ' ';
    cout << '\n';
  }
  return 0;
}