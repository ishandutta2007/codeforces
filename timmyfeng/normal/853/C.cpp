#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

template <class T>
struct fenwick_2d {

  vector<int> vals[N];
  vector<T> tree[N];

  int get(int x, int y) {
    return upper_bound(vals[x].begin(), vals[x].end(), y) - vals[x].begin();
  }

  void add(int x, int y) {
    for ( ; x < N; x += x & -x) {
      vals[x].push_back(y);
    }
  }

  void build() {
    for (int i = 1; i < N; ++i) {
      sort(vals[i].begin(), vals[i].end());
      vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
      tree[i].resize(vals[i].size() + 1u);
    }
  }

  void update(int x, int y, T val) {
    for ( ; x < N; x += x & -x) {
      for (int i = get(x, y); i < int(tree[x].size()); i += i & -i) {
        tree[x][i] += val;
      }
    }
  }

  T query(int x, int y) {
    T res = 0;
    for ( ; x > 0; x -= x & -x) {
      for (int i = get(x, y); i > 0; i -= i & -i) {
        res += tree[x][i];
      }
    }
    return res;
  }

  T query(int x1, int y1, int x2, int y2) {
    return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x1 - 1, y2) - query(x2, y1 - 1);
  }

};

fenwick_2d<int> fenw;

int64_t choose2(int a) {
  return 1LL * a * (a - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<array<int, 2>> points;
  for (int i = 1; i <= n; ++i) {
    int j;
    cin >> j;
    fenw.add(i, j);
    points.push_back({i, j});
  }

  fenw.build();
  for (auto [x, y] : points) {
    fenw.update(x, y, 1);
  }

  while (q--) {
    int l, d, r, u;
    cin >> l >> d >> r >> u;

    int64_t ans =
      choose2(n) -
      choose2(l - 1) -
      choose2(n - r) -
      choose2(d - 1) -
      choose2(n - u) +
      choose2(fenw.query(1, 1, l - 1, d - 1)) +
      choose2(fenw.query(1, u + 1, l - 1, n)) +
      choose2(fenw.query(r + 1, 1, n, d - 1)) +
      choose2(fenw.query(r + 1, u + 1, n, n));

    cout << ans << "\n";
  }
}