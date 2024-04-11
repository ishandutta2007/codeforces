#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> size;

  union_find(int n) {
    par.resize(n);
    size.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find(int u) {
    if (par[u] != u) {
      par[u] = find(par[u]);
    }
    return par[u];
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    par[u] = v;
    return true;
  }

};

const int M = 1000000007;
const int N = 500000;

int basis[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  union_find dsu(m + 1);
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      x = dsu.find(x - 1);
      if (x != m) {
        dsu.unite(x, m);
        basis[x] = i;
      }
    } else {
      int x, y;
      cin >> x >> y;
      x = dsu.find(x - 1), y = dsu.find(y - 1);
      if (x > y) {
        swap(x, y);
      }
      if (x != m && x != y) {
        dsu.unite(x, y);
        basis[x] = i;
      }
    }
  }

  int t = 1;
  vector<int> s;
  for (int i = 0; i < m; ++i) {
    if (basis[i] > 0) {
      s.push_back(basis[i]);
      t = t * 2 % M;
    }
  }
  sort(s.begin(), s.end());

  cout << t << " " << s.size() << "\n";
  for (auto i : s) {
    cout << i << " ";
  }
  cout << "\n";
}