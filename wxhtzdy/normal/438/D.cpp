#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[100050];
ll st[400050], mx[400050];

void build(int node, int l, int r) {
  if (l > r) return;
  if (l == r) {
    st[node] = mx[node] = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] + st[node * 2 + 1];
  mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int val) {
  if (l > r || r < pos || l > pos) return;
  if (l == r) {
    st[node] = mx[node] = a[l] = val;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid) {
    update(node * 2, l, mid, pos, val);
  } else {
    update(node * 2 + 1, mid + 1, r, pos, val);
  }
  st[node] = st[node * 2] + st[node * 2 + 1];
  mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
}

void update(int node, int l, int r, int ll, int rr, int x) {
  if (l > r || r < ll || l > rr || mx[node] < x) return;
  if (l == r) {
    a[l] %= x;
    st[node] = mx[node] = a[l];
    return;
  }
  int mid = l + r >> 1;
  update(node * 2, l, mid, ll, rr, x);
  update(node * 2 + 1, mid + 1, r, ll, rr, x);
  st[node] = st[node * 2] + st[node * 2 + 1];
  mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
}

ll get(int node, int l, int r, int ll, int rr) {
  if (l > r || r < ll || l > rr) return 0LL;
  if (ll <= l && r <= rr) return st[node];
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];

  build(1, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << get(1, 0, n - 1, l, r) << '\n';
    }
    if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      update(1, 0, n - 1, l, r, x);
    }
    if (type == 3) {
      int i, x;
      cin >> i >> x;
      --i;
      update(1, 0, n - 1, i, x);
    }
  }
}