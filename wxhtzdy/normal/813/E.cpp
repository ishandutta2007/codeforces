#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 1e5 + 5;

int a[N], b[N];
vector<int> pos[N];
vector<int> st[4 * N];

void build(int node, int l, int r) {
  if (l > r) return;
  if (l == r) {
    st[node].push_back(b[l]);
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  for (int i : st[node * 2]) st[node].push_back(i);
  for (int i : st[node * 2 + 1]) st[node].push_back(i);
  sort(st[node].begin(), st[node].end());
}

int get(int node, int l, int r, int ll, int rr, int val) {
  if (l > r || l > rr || r < ll) return 0;
  if (ll <= l && r <= rr) {
    if (st[node].empty() || *st[node].begin() > l) return 0;
    return (int) (lower_bound(st[node].begin(), st[node].end(), val) - st[node].begin());
  }
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr, val) + get(node * 2 + 1, mid + 1, r, ll, rr, val);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (int) pos[i].size(); j++) {
      if (j >= k) b[pos[i][j]] = pos[i][j - k];
      else b[pos[i][j]] = -1;
    }
  }
  build(1, 0, n - 1);
  int q, last = 0;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = (l + last) % n + 1;
    r = (r + last) % n + 1;
    if (l > r) swap(l, r);
    --l, --r;
    last = get(1, 0, n - 1, l, r, l);
    cout << last << '\n';
  }
}