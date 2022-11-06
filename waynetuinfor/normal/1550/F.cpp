#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

constexpr int kInf = 1E8;

struct Node {
  array<int, 4> value;
  array<int, 4> from;

  int mx, mn, mxf, mnf;

  Node() = default;

  explicit Node(int p, int v) : mx(v), mn(v), mxf(p), mnf(p) {
    fill(from.begin(), from.end(), p);
    fill(value.begin(), value.end(), kInf);
  }
};

Node Merge(const Node &lhs, const Node &rhs) {
  Node result{};
  if (lhs.mx > rhs.mx) {
    result.mx = lhs.mx;
    result.mxf = lhs.mxf;
  } else {
    result.mx = rhs.mx;
    result.mxf = rhs.mxf;
  }
  if (lhs.mn < rhs.mn) {
    result.mn = lhs.mn;
    result.mnf = lhs.mnf;
  } else {
    result.mn = rhs.mn;
    result.mnf = rhs.mnf;
  }
  for (int i = 0; i < 4; ++i) {
    if (lhs.value[i] < rhs.value[i]) {
      result.value[i] = lhs.value[i];
      result.from[i] = lhs.from[i];
    } else {
      result.value[i] = rhs.value[i];
      result.from[i] = rhs.from[i];
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q, S, D;
  cin >> N >> Q >> S >> D;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  S--;

  vector<Node> tree(N * 4);
  constexpr array<int, 4> kInitTag = {-kInf, kInf, kInf, -kInf};
  vector<array<int, 4>> tags(N * 4, kInitTag);
  vector<int> dist(N, kInf);

  auto Build = [&]() {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        tree[o] = Node(l, A[l]);
        return;
      }
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    return dfs(dfs, 0, N);
  };

  Build();

  auto Apply = [&](Node &nd, int x, int v) {
    if (x == 0) {
      if (nd.mn + D - v < nd.value[0]) {
        nd.value[0] = nd.mn + D - v;
        nd.from[0] = nd.mnf;
      }
    } else if (x == 1) {
      if (v - nd.mx - D < nd.value[1]) {
        nd.value[1] = v - nd.mx - D;
        nd.from[1] = nd.mxf;
      }
    } else if (x == 2) {
      if (D - nd.mx + v < nd.value[2]) {
        nd.value[2] = D - nd.mx + v;
        nd.from[2] = nd.mxf;
      }
    } else {
      if (nd.mn - v - D < nd.value[3]) {
        nd.value[3] = nd.mn - v - D;
        nd.from[3] = nd.mnf;
      }
    }
  };

  auto ApplyTag = [&](int &t, int x, int v) {
    if (x == 0 || x == 3) {
      t = max(t, v);
    } else {
      t = min(t, v);
    }
  };

  auto Modify = [&](int ql, int qr, int x, int v) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        Apply(tree[o], x, v);
        ApplyTag(tags[o][x], x, v);
        return;
      }
      for (int k = 1; k <= 2; ++k) {
        for (int i = 0; i < 4; ++i) {
          Apply(tree[o * 2 + k], i, tags[o][i]);
          ApplyTag(tags[o * 2 + k][i], i, tags[o][i]);
        }
      }
      tags[o] = kInitTag;
      int m = (l + r) >> 1;
      dfs(dfs, l, m, o * 2 + 1);
      dfs(dfs, m, r, o * 2 + 2);
      tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    return dfs(dfs, 0, N);
  };

  auto Remove = [&](int p) {
    auto dfs = [&](auto dfs, int l, int r, int o = 0) -> void {
      if (r - l == 1) {
        fill(tree[o].value.begin(), tree[o].value.end(), kInf);
        tree[o].mx = -kInf;
        tree[o].mn = kInf;
        return;
      }
      for (int k = 1; k <= 2; ++k) {
        for (int i = 0; i < 4; ++i) {
          Apply(tree[o * 2 + k], i, tags[o][i]);
          ApplyTag(tags[o * 2 + k][i], i, tags[o][i]);
        }
      }
      tags[o] = kInitTag;
      int m = (l + r) >> 1;
      if (p < m) dfs(dfs, l, m, o * 2 + 1);
      else dfs(dfs, m, r, o * 2 + 2);
      tree[o] = Merge(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    return dfs(dfs, 0, N);
  };

  dist[S] = 0;
  Remove(S);
  int l = lower_bound(A.begin(), A.end(), A[S] - D) - A.begin();
  int r = upper_bound(A.begin(), A.end(), A[S] + D) - A.begin();

  auto Debug = [&](const Node &nd) {
    cout << "DEBUG: ";
    for (int i = 0; i < 4; ++i) cout << "(" << nd.value[i] << ", " << nd.from[i] << ") ";
    cout << endl;
  };

  Modify(l, S, 0, A[S]);
  Modify(0, l, 1, A[S]);
  Modify(S + 1, r, 2, A[S]);
  Modify(r, N, 3, A[S]);

  int pbest = -kInf;

  for (int it = 0; it < N - 1; ++it) {
    int best = kInf, opt = -1;
    for (int i = 0; i < 4; ++i) {
      if (tree[0].value[i] < best) {
        best = tree[0].value[i];
        opt = tree[0].from[i];
      }
    }
    best = max(best, pbest);
    dist[opt] = pbest = best;
    Remove(opt);
    int l = lower_bound(A.begin(), A.end(), A[opt] - D) - A.begin();
    int r = upper_bound(A.begin(), A.end(), A[opt] + D) - A.begin();
    Modify(l, opt, 0, A[opt]);
    Modify(0, l, 1, A[opt]);
    Modify(opt + 1, r, 2, A[opt]);
    Modify(r, N, 3, A[opt]);
  }

  while (Q--) {
    int i, k;
    cin >> i >> k;
    cout << (dist[i - 1] <= k ? "YES" : "NO") << "\n";
  }
  return 0;
}