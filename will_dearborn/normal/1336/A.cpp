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

vvi g, g1;
vi sz, tmp, dep, pr;

void dfs(int v, int p) {
  sz[v] = tmp[v];
  for (int nv : g[v]) if (nv != p) {
    dep[nv] = dep[v] + 1;
    dfs(nv, v);
    pr[nv] = v;
    g1[v].push_back(nv);
    sz[v] += sz[nv];
  }
//  cerr << v + 1 << ' ' << tmp[v] << ' ' << sz[v] << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  g.resize(n);
  g1.resize(n);
  dep.assign(n, 0);
  tmp.assign(n, 1);
  sz.assign(n, 1);
  pr.assign(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  ll s = 0;
  vi deg(n);
  set<pii> q;
  for (int i = 0; i < n; ++i) {
    deg[i] = g1[i].size();
    if (deg[i] == 0) q.insert(pii(sz[i] - 1 - dep[i], i));
  }
  for (int t = 0; t < k; ++t) {
    assert(!q.empty());
    s -= q.begin()->first;
    int v = q.begin()->second;
//    cerr << v + 1 << ' ' << s << endl;
    q.erase(q.begin());
    assert(pr[v] != -1);
    --deg[pr[v]];
    if (deg[pr[v]] == 0) {
      q.insert(pii(-dep[pr[v]] + sz[pr[v]] - 1, pr[v]));
    }
  }
/*  vii ts(n);
  for (int i = 0; i < n; ++i) ts[i] = pii(sz[i], i);
  sort(ts.rbegin(), ts.rend());
  for (int i = 0; i < n - k; ++i) tmp[ts[i].second] = 0;
  dfs(0, -1);
  for (int i = 0; i < n; ++i) if (!tmp[i]) {
    cerr << i + 1 << ' ' << sz[i] << endl;
    s += sz[i];
  }*/
  cout << s << endl;
  return 0;
}