#include <bits/stdc++.h>
using namespace std;

struct union_find {

  vector<int> par;
  vector<int> sz;

  union_find(int n) {
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
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
    return true;
  }

};

const int N = 1'000;

int ndx[N];
int x[N];
int y[N];

template <int T>
bool check(union_find &dsu, array<int, T> a) {
  bool ok = true;
  for (int i = 0; i < T; ++i) {
    for (int j = i + 1; j < T; ++j) {
      ok &= (dsu.find(a[i]) != dsu.find(a[j]));
    }
  }
  return ok;
}

int dist(int a, int b) {
  return max(abs(x[a] - x[b]), abs(y[a] - y[b]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 3>> edges;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  iota(ndx, ndx + n, 0);

  sort(ndx, ndx + n, [&](int a, int b) {
    return (x[a] == x[b]) ? y[a] < y[b] : x[a] < x[b];
  });
  for (int i = 1; i < n; ++i) {
    if (x[ndx[i]] == x[ndx[i - 1]]) {
      edges.push_back({y[ndx[i]] - y[ndx[i - 1]], ndx[i - 1], ndx[i]});
    }
  }

  sort(ndx, ndx + n, [&](int a, int b) {
    return (y[a] == y[b]) ? x[a] < x[b] : y[a] < y[b];
  });
  for (int i = 1; i < n; ++i) {
    if (y[ndx[i]] == y[ndx[i - 1]]) {
      edges.push_back({x[ndx[i]] - x[ndx[i - 1]], ndx[i - 1], ndx[i]});
    }
  }

  int lo = 0;
  int hi = INT_MAX;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    int cnt = n;
    union_find dsu(n);
    for (auto [w, u, v] : edges) {
      if (w <= mid) {
        cnt -= dsu.unite(u, v);
      }
    }

    bool ok = (cnt == 1);
    if (cnt == 2) {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (check<2>(dsu, {i, j})) {
            ok |= (mid >= dist(i, j) || ((x[i] == x[j] || y[i] == y[j]) && mid >= (dist(i, j) + 1) / 2));
          }
        }
      }
    } else if (cnt == 3) {
      for (auto [w, u, v] : edges) {
        for (int i = 0; i < n; ++i) {
          if (check<3>(dsu, {u, v, i})) {
            ok |= (mid >= max(dist(u, i), dist(v, i)));
          }
        }
      }
    } else if (cnt == 4) {
      for (auto [wi, ui, vi] : edges) {
        for (auto [wj, uj, vj] : edges) {
          if (check<4>(dsu, {ui, vi, uj, vj})) {
            ok |= (mid >= max({dist(ui, uj), dist(ui, vj), dist(vi, uj), dist(vi, vj)}));
          }
        }
      }
    }

    if (ok) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << (lo == INT_MAX ? -1 : lo) << "\n";
}