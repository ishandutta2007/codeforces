#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

namespace {

struct DSU {
  vector<int> p;
  vector<ll> vl;
  vector<vector<int>> in_comp;
  int x;
  DSU(int n, const vector<ll> & vl, int x) : vl(vl), x(x) {
    p.resize(n);
    iota(all(p), 0);
    in_comp.resize(n);
    for (int i = 0; i < n; i++) {
      in_comp[i] = {i};
    }
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return false;
    }
    if (SZ(in_comp[a]) < SZ(in_comp[b])) {
      swap(a, b);
    }
    assert(vl[a] + vl[b] >= x);
    vl[a] += vl[b] - x;
    p[b] = a;
    for (int v : in_comp[b]) {
      in_comp[a].push_back(v);
    }
    return true;
  }
};

}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  ll sum = 0;
  vector<ll> vl(n);
  for (int i = 0; i < n; i++) {
    cin >> vl[i];
    sum += vl[i];
  }
  if (sum < (n - 1) * 1ll * x) {
    cout << "NO\n";
    return 0; 
  }
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  DSU G(n, vl, x);
  set<pair<ll, int>, greater<pair<ll, int>>> comps;
  for (int i = 0; i < n; i++) {
    comps.insert({vl[i], i});
  }
  cout << "YES\n";
  while (SZ(comps) > 1) {
    int current_component = comps.begin()->second;
    comps.erase(comps.begin());
    while (!G.in_comp[current_component].empty()) {
      int v = G.in_comp[current_component].back();
      while (!g[v].empty() && G.find(g[v].back().first) == current_component) {
        g[v].pop_back();
      }
      if (!g[v].empty()) {
        cout << g[v].back().second << '\n';
        int other_component = G.find(g[v].back().first);
        comps.erase({G.vl[other_component], other_component});
        assert(G.merge(current_component, other_component));
        int new_component = G.find(current_component);
        comps.insert({G.vl[new_component], new_component});
        break;
      }
      else {
        G.in_comp[current_component].pop_back();
      }
    }
  }
  return 0;
}