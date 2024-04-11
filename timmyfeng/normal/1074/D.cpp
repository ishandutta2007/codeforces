#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;

struct disjoint_set_union {

  int val[N];
  int par[N];
  int sz[N];

  void init(int n) {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
  }

  pair<int, int> find(int u) {
    if (par[u] != u) {
      auto res = find(par[u]);
      par[u] = res.first;
      val[u] ^= res.second;
    }
    return {par[u], val[u]};
  }

  bool unite(int u, int v, int x) {
    auto uu = find(u);
    auto vv = find(v);
    if (uu.first == vv.first)
      return false;

    if (sz[uu.first] > sz[vv.first]) {
      swap(uu, vv);
    }
    par[uu.first] = vv.first;
    sz[vv.first] += sz[uu.first];
    val[uu.first] ^= uu.second ^ vv.second ^ x;
    return true;
  }

} dsu;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  int cnt = 0;
  int last = 0;
  dsu.init(2 * q);
  map<int, int> ndx;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;

    l ^= last;
    r ^= last;
    if (l > r) {
      swap(l, r);
    }
    ++r;

    for (int i : {l, r}) {
      if (ndx.count(i) == 0) {
        ndx[i] = cnt;
        ++cnt;
      }
    }

    if (t == 1) {
      int x;
      cin >> x;
      dsu.unite(ndx[l], ndx[r], x ^ last);
    } else {
      auto u = dsu.find(ndx[l]);
      auto v = dsu.find(ndx[r]);
      if (u.first == v.first) {
        last = u.second ^ v.second;
        cout << last << "\n";
      } else {
        cout << -1 << "\n";
        last = 1;
      }
    }
  }
}