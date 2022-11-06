#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), q(n), rv(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    rv[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    q[i]--;
  }
  vector<int> cnt(n);
  vector<int> tree(n * 4), tag(n * 4);

  constexpr int kInf = 1'000'000'00;

  for (int i = 0; i < n * 4; ++i) {
    tree[i] = -kInf;
  }

  auto Modify = [&](int ql, int qr, int v) {
    auto Impl = [&](auto self, int l, int r, int o = 0) {
      if (l >= qr || ql >= r) return;
      if (l >= ql && r <= qr) {
        tree[o] += v;
        tag[o] += v;
        return;
      }
      for (int k = 1; k <= 2; ++k) {
        tree[o * 2 + k] += tag[o];
        tag[o * 2 + k] += tag[o];
      }
      tag[o] = 0;
      int m = (l + r) >> 1;
      self(self, l, m, o * 2 + 1);
      self(self, m, r, o * 2 + 2);
      tree[o] = max(tree[o * 2 + 1], tree[o * 2 + 2]);
    };
    Impl(Impl, 0, n);
  };

  int ptr = n - 1;
  Modify(rv[n - 1], rv[n - 1] + 1, kInf);
  Modify(0, rv[n - 1] + 1, 1);
  for (int i = 0; i < n; ++i) {
    cout << ptr + 1 << " ";
    if (i == n - 1) break;
    Modify(0, q[i] + 1, -1);
    while (tree[0] <= 0) {
      assert(ptr > 0);
      int k = rv[ptr - 1];
      Modify(k, k + 1, kInf);
      Modify(0, k + 1, 1);
      ptr--;
    }
    // for (int k = n - 1; k >= 0; --k) {
      // if (n - k > i) {
        // cout << k + 1 << "\n";
        // break;
      // }
      // bool ok = false;
      // int g = 0;
      // for (int j = 0; j < n; ++j) {
        // if (p[j] < k) continue;
        // int pv = 0;
        // for (int o = j; o < n; ++o) pv += cnt[o];
        // if (pv < n - k - g) ok = true;
        // g++;
      // }
      // if (ok) {
        // cout << k + 1 << "\n";
        // break;
      // }
    // }
    // cnt[q[i]] = 1;
  }
}