#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

struct segtree {
  vector<int> a, lzy;
  void init() {
    a.resize(maxn * 2);
    lzy.resize(maxn * 2);
    for (int i = 0; i < maxn * 2; i++) a[i] = lzy[i] = 0;
  }
  void add(int node, int l, int r, int p, int val) {
    if (l > r || r < p || l > p) return;
    if (l == r) {
      assert(l == p);
      a[node] += val;
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      add(node * 2, l, mid, p, val);
    } else {
      add(node * 2 + 1, mid + 1, r, p, val);
    }
    a[node] = a[node * 2] + a[node * 2 + 1];
  }
  void push(int node, int l, int r) {
    if (lzy[node] == 1) {
      a[node] = (r - l + 1) - a[node];
      if (l != r) {
        lzy[node * 2] ^= 1;
        lzy[node * 2 + 1] ^= 1;
      }
    }
    lzy[node] = 0;
  }
  void modify(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      lzy[node] ^= 1;
      push(node, l, r);
      return;
    }
    int mid = l + r >> 1;
    modify(node * 2, l, mid, ll, rr);
    modify(node * 2 + 1, mid + 1, r, ll, rr);
    a[node] = a[node * 2] + a[node * 2 + 1];
  }
  int get(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) {
      return a[node];
    }
    int mid = l + r >> 1;
    return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
  }
} st[20];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 20; i++) {
    st[i].init();
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) {
        st[i].add(1, 0, n - 1, j, 1);
      }
    }
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int foo;
    cin >> foo;
    if (foo == 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = 0;
      for (int i = 0; i < 20; i++) {
        ans += (1 << i) * st[i].get(1, 0, n - 1, l, r);
      }
      cout << ans << '\n';
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      for (int i = 0; i < 20; i++) {
        if (x & (1 << i)) {
          st[i].modify(1, 0, n - 1, l, r);
        }
      }
    }
  }
  return 0;
}