#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 3e5 + 5;
const int M = N * 4;

int a[N], cnt[1000050];
ll st[M], mx[M];

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

void update(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll || mx[node] <= 2) return;
  if (l == r) {
    a[l] = cnt[a[l]];
    st[node] = mx[node] = a[l];
    return;
  }
  int mid = l + r >> 1;
  update(node * 2, l, mid, ll, rr);
  update(node * 2 + 1, mid + 1, r, ll, rr);
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

  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= 1e6; i++) {
    for (int j = i; j <= 1e6; j += i) {
      cnt[j]++;
    }
  }
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
      update(1, 0, n - 1, l, r);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << get(1, 0, n - 1, l, r) << '\n';
    }
  }
}