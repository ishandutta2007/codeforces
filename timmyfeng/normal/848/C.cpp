#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

array<int, 3> queries[N];
set<int> pos[N];
int a[N];

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

};

fenwick_2d<int64_t> fenw;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]].insert(i);
  }

  vector<array<int, 4>> segments;
  for (int i = 1; i <= n; ++i) {
    for (auto it = pos[i].begin(); it != pos[i].end(); ++it) {
      if (it != pos[i].begin()) {
        auto prv = it;
        --prv;
        segments.push_back({-1, *prv, *it, 1});
      }
    }
  }

  auto process = [&](int i, int u, int v, int c) {
    auto prv = pos[v].find(u);
    auto nxt = prv;

    if (prv != pos[v].begin()) {
      --prv;
      assert(*prv <= u);
      segments.push_back({i, *prv, u, c});
    }

    if (nxt != --pos[v].end()) {
      ++nxt;
      assert(u <= *nxt);
      segments.push_back({i, u, *nxt, c});
    }

    if (*prv != u && *nxt != u) {
      assert(*prv <= *nxt);
      segments.push_back({i, *prv, *nxt, -c});
    }
  };

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> queries[i][j];
    }

    auto [t, u, v] = queries[i];
    if (t == 1) {
      process(i, u, a[u], -1);
      pos[a[u]].erase(u);
      pos[v].insert(u);
      process(i, u, v, 1);
      a[u] = v;
    }
  }

  for (auto [i, x, y, c] : segments) {
    fenw.add(x, y);
  }
  fenw.build();

  int ptr = 0;
  for (int i = 0; i < m; ++i) {
    auto [t, u, v] = queries[i];

    while (ptr < int(segments.size()) && segments[ptr][0] <= i) {
      auto [i, l, r, c] = segments[ptr];
      fenw.update(l, r, (r - l) * c);
      ++ptr;
    }

    if (t == 2) {
      cout << fenw.query(v, v) - fenw.query(u - 1, v) << "\n";
    }
  }
}