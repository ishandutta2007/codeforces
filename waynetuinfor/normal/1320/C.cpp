#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(n), ca(n);
  constexpr int kC = 1'000'000;
  constexpr int kInf = 2'000'000'000;
  vector<int> cost(kC, kInf);
  for (int i = 0; i < n; ++i) cin >> a[i] >> ca[i];
  for (int i = 0; i < m; ++i) {
    int b, cb;
    cin >> b >> cb;
    cost[b - 1] = min(cost[b - 1], cb);
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

  vector<int64_t> tree(kC * 4, 0), tag(kC * 4, 0);

  auto BuildTree = [&]() {
    auto BuildImpl = [&](auto self, int l, int r, int o = 0) {
      if (r - l == 1) {
        tree[o] = -cost[l];
        return;
      }
      int m = (l + r) >> 1;
      self(self, l, m, o * 2 + 1);
      self(self, m, r, o * 2 + 2);
      tree[o] = max(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    BuildImpl(BuildImpl, 0, kC);
  };

  auto Push = [&](int o) {
    for (int v = 1; v <= 2; ++v) {
      tree[o * 2 + v] += tag[o];
      tag[o * 2 + v] += tag[o];
    }
    tag[o] = 0;
  };

  auto Modify = [&](int p, int v) {
    auto ModifyImpl = [&](auto self, int l, int r, int ql, int qr, int v, int o = 0) {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        tree[o] += v;
        tag[o] += v;
        return;
      }
      Push(o);
      int m = (l + r) >> 1;
      self(self, l, m, ql, qr, v, o * 2 + 1);
      self(self, m, r, ql, qr, v, o * 2 + 2);
      tree[o] = max(tree[o * 2 + 1], tree[o * 2 + 2]);
    };

    ModifyImpl(ModifyImpl, 0, kC, p, kC, v);
  };

  BuildTree();

  vector<int> x(p), y(p), z(p);
  for (int i = 0; i < p; ++i) cin >> x[i] >> y[i] >> z[i];

  vector<int> ord2(p);
  iota(ord2.begin(), ord2.end(), 0);
  sort(ord2.begin(), ord2.end(), [&](int i, int j) { return x[i] < x[j]; });
  int64_t ans = -1'000'000'000'000'000LL;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < p && x[ord2[j]] < a[ord[i]]) {
      Modify(y[ord2[j]], z[ord2[j]]);
      j++;
    }
    ans = max(ans, -ca[ord[i]] + tree[0]);
  }
  cout << ans << "\n";
}