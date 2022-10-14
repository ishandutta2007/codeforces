#include <bits/stdc++.h>

using namespace std;

class dsu {
  public:
  vector<int> p;
  vector<int> sz;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  long long sum_mx = 0;
  dsu L(n);
  vector<bool> was(n, false);
  for (int id = 0; id < n; id++) {
    int i = order[id];
    was[i] = true;
    vector<int> v;
    for (int j : g[i]) {
      if (!was[j]) {
        continue;
      }
      v.push_back(L.sz[L.get(j)]);
      L.unite(i, j);
    }
    sum_mx += a[i];
    long long s = 0;
    for (int j = 0; j < v.size(); j++) {
      sum_mx += (long long) v[j] * a[i];
      sum_mx += s * (long long) v[j] * a[i];
      s += v[j];
    }
  }
  long long sum_mn = 0;
  dsu R(n);
  for (int i = 0; i < n; i++) {
    was[i] = false;
  }
  for (int id = n - 1; id >= 0; id--) {
    int i = order[id];
    was[i] = true;
    vector<int> v;
    for (int j : g[i]) {
      if (!was[j]) {
        continue;
      }
      v.push_back(R.sz[R.get(j)]);
      R.unite(i, j);
    }
    sum_mn += a[i];
    long long s = 0;
    for (int j = 0; j < v.size(); j++) {
      sum_mn += (long long) v[j] * a[i];
      sum_mn += s * (long long) v[j] * a[i];
      s += v[j];
    }
  }
  cout << sum_mx - sum_mn << '\n';
  return 0;
}