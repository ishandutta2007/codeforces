#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *left = nullptr, *right = nullptr;
  int mini, lazy;

  void apply(int x) {
    mini += x, lazy += x;
  }

  void pull() {
    mini = min(left->mini, right->mini);
  }

  void push() {
    if (lazy != 0) {
      left->apply(lazy);
      right->apply(lazy);
      lazy = 0;
    }
  }

  segtree(int l, int r, int *h) {
    lazy = 0;
    if (l == r) {
      mini = h[l] + l;
    } else {
      int m = (l + r) / 2;
      left = new segtree(l, m, h);
      right = new segtree(m + 1, r, h);
      pull();
    }
  }

  void update(int a, int b, int x, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(x);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, x, l, m);
      right->update(a, b, x, m + 1, r);
      pull();
    }
  }

};

const int N = 100000;

int h[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  segtree *towers = new segtree(0, n - 1, h);
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    ans = max(ans, min({towers->mini, i + 1, n - i}));
    towers->update(0, i, 1, 0, n - 1);
    towers->update(i + 1, n - 1, -1, 0, n - 1);
  }

  cout << ans << "\n";
}