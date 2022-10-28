#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int M = 1e9 + 7;

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

struct union_find {

  int par[N];
  int cnt[N];
  int sz[N];

  void init(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;

    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    par[u] = v;
    sz[v] += sz[u];
    cnt[v] += cnt[u];
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> vals_x;
  vector<int> vals_y;
  vector<array<int, 2>> points;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
    vals_x.push_back(x);
    vals_y.push_back(y);
  }

  sort(vals_x.begin(), vals_x.end());
  sort(vals_y.begin(), vals_y.end());
  vals_x.erase(unique(vals_x.begin(), vals_x.end()), vals_x.end());
  vals_y.erase(unique(vals_y.begin(), vals_y.end()), vals_y.end());

  dsu.init(vals_x.size() + vals_y.size());
  for (auto [x, y] : points) {
    x = lower_bound(vals_x.begin(), vals_x.end(), x) - vals_x.begin();
    y = lower_bound(vals_y.begin(), vals_y.end(), y) - vals_y.begin();
    dsu.unite(x, int(vals_x.size()) + y);
    ++dsu.cnt[dsu.find(x)];
  }

  int ans = 1;
  for (int i = 0; i < int(vals_x.size() + vals_y.size()); ++i) {
    if (dsu.par[i] == i) {
      ans = mul(ans, sub(mod_pow(2, dsu.sz[i]), dsu.sz[i] > dsu.cnt[i]));
      assert(dsu.sz[i] <= dsu.cnt[i] + 1);
    }
  }
  cout << ans << "\n";
}