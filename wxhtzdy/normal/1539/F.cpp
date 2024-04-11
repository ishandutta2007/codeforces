#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

namespace segtree {
  int mn[4 * N], mx[4 * N], lzy[4 * N];
  void push(int node) {
    mn[node * 2] += lzy[node];
    mn[node * 2 + 1] += lzy[node];
    mx[node * 2] += lzy[node];
    mx[node * 2 + 1] += lzy[node];
    lzy[node * 2] += lzy[node];
    lzy[node * 2 + 1] += lzy[node];
    lzy[node] = 0;
  }
  void pull(int node) {
    mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
    mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
  }
  void build(int node, int l, int r) {
    lzy[node] = 0;
    if (l == r) {
      mn[node] = l + 1;
      mx[node] = l + 1;
      return;
    }
    int mid = l + r >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    pull(node);
  }
  void modify(int node, int l, int r, int ll, int rr, int v) {
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      mn[node] += v;
      mx[node] += v;
      lzy[node] += v;
      return;
    }
    push(node);
    int mid = l + r >> 1;
    modify(node * 2, l, mid, ll, rr, v);
    modify(node * 2 + 1, mid + 1, r, ll, rr, v);
    pull(node);
  }
  int get_mn(int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) return 1e9;
    if (ll <= l && r <= rr) return mn[node];
    push(node);
    int mid = l + r >> 1;
    int L = get_mn(node * 2, l, mid, ll, rr);
    int R = get_mn(node * 2 + 1, mid + 1, r, ll, rr);
    pull(node);
    return min(L, R);
  }
  int get_mx(int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) return -1e9;
    if (ll <= l && r <= rr) return mx[node];
    push(node);
    int mid = l + r >> 1;
    int L = get_mx(node * 2, l, mid, ll, rr);
    int R = get_mx(node * 2 + 1, mid + 1, r, ll, rr);
    pull(node);
    return max(L, R);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]].push_back(i);
  }
  vector<int> ans(n);
  segtree::build(1, 0, n - 1);
  for (int i = n - 1; i >= 0; i--) {
    for (int x : pos[i]) {
      segtree::modify(1, 0, n - 1, x, n - 1, -1);
      int tmp = segtree::get_mx(1, 0, n - 1, x, n - 1) - min(0, segtree::get_mn(1, 0, n - 1, 0, x));
      ans[x] = max(ans[x], tmp / 2);
      segtree::modify(1, 0, n - 1, x, n - 1, +1);
    }
    for (int x : pos[i]) {
      segtree::modify(1, 0, n - 1, x, n - 1, -2);
    }
  }
  segtree::build(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    for (int x : pos[i]) {
      segtree::modify(1, 0, n - 1, x, n - 1, -1);
      int tmp = segtree::get_mx(1, 0, n - 1, x, n - 1) - min(0, segtree::get_mn(1, 0, n - 1, 0, x));
      ans[x] = max(ans[x], (tmp + 1) / 2);
      segtree::modify(1, 0, n - 1, x, n - 1, +1);
    }
    for (int x : pos[i]) {
      segtree::modify(1, 0, n - 1, x, n - 1, -2);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}