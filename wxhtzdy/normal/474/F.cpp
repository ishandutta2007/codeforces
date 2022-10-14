#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = 20;

struct node{
  int val, cnt;
} mn[N][L];

node comb(node x, node y) {
  node ret;
  ret.val = min(x.val, y.val);
  if (x.val < y.val) ret.cnt = x.cnt;
  if (x.val > y.val) ret.cnt = y.cnt;
  if (x.val == y.val) ret.cnt = x.cnt + y.cnt;
  return ret;
}

int n, a[N], nzd[N][L];

void build() {
  for (int i = 0; i < n; i++) {
    nzd[i][0] = a[i];
  }
  for (int j = 1; j < L; j++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << j) <= n) {
        nzd[i][j] = __gcd(nzd[i][j - 1], nzd[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    mn[i][0].val = a[i];
    mn[i][0].cnt = 1;
  }
  for (int j = 1; j < L; j++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << j) <= n) {
        mn[i][j] = comb(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}

int get(int l, int r) {
  int sz = r - l + 1;
  int need = 0;
  int pos = l;
  for (int i = L - 1; i >= 0; i--) {
    if (sz & (1 << i)) {
      need = __gcd(need, nzd[pos][i]);
      pos += (1 << i);
    }
  }
  node res;
  res.val = 1e9 + 5;
  pos = l;
  for (int i = L - 1; i >= 0; i--) {
    if (sz & (1 << i)) {
      res = comb(res, mn[pos][i]);
      pos += (1 << i);
    }
  }
  if (res.val != need) {
    return 0;
  }
  return res.cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << (r - l + 1) - get(l, r) << '\n';
  }
  return 0;
}