#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 1e5 + 5;

struct segtree {
  vector<int> a, lzy;
  segtree() {
    a.resize(4 * N);
    lzy.resize(4 * N);
  }
  void push(int node, int l, int r) {
    if (lzy[node] == -1) a[node] = 0;
    if (lzy[node] == 1) a[node] = lzy[node] * (r - l + 1);
    if (l != r && lzy[node] != 0) {
      lzy[node * 2] = lzy[node];
      lzy[node * 2 + 1] = lzy[node];
    }
    lzy[node] = 0;
  }
  void update(int node, int l, int r, int ll, int rr, int val) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      lzy[node] += val;
      push(node, l, r);
      return;
    }
    int mid = l + r >> 1;
    update(node * 2, l, mid, ll, rr, val);
    update(node * 2 + 1, mid + 1, r, ll, rr, val);
    a[node] = a[node * 2] + a[node * 2 + 1];
  }
  int get(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) return a[node];
    int mid = l + r >> 1;
    return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
  }
} st[26];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int c = (int) (s[i] - 'a');
    st[c].update(1, 0, n - 1, i, i, 1);
  }

  while (q--) {
    int l, r, op;
    cin >> l >> r >> op;
    --l, --r;
    vector<int> cnt(26);
    for (int i = 0; i < 26; i++) {
      cnt[i] = st[i].get(1, 0, n - 1, l, r);
      if (cnt[i] > 0) {
        st[i].update(1, 0, n - 1, l, r, -1);
      }
    }
    if (op == 1) {
      for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        st[i].update(1, 0, n - 1, l, l + cnt[i] - 1, 1);
        l += cnt[i];
      }
    } else {
      for (int i = 25; i >= 0; i--) {
        if (cnt[i] == 0) continue;
        st[i].update(1, 0, n - 1, l, l + cnt[i] - 1, 1);
        l += cnt[i];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (st[j].get(1, 0, n - 1, i, i) == 1) {
        cout << (char) (j + 'a');
      }
    }
  }
}