#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 4 * N;
const int inf = 1e9;

int lst[N];
pair<int, int> st[M];

void klir() {
  for (int i = 0; i < M; i++) {
    st[i] = {inf, 0};
  }
  for (int i = 0; i < N; i++) {
    lst[i] = -1;
  }
}

void modify(int node, int l, int r, int pos, int val) {
  if (l == r) {
    st[node] = {val, l};
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid) modify(node * 2, l, mid, pos, val);
  else modify(node * 2 + 1, mid + 1, r, pos, val);
  st[node] = min(st[node * 2], st[node * 2 + 1]);
}

pair<int, int> get(int node, int l, int r, int ll, int rr) {
  if (l > r || r < ll || l > rr) return {1e9, 0};
  if (ll <= l && r <= rr) return st[node];
  int mid = l + r >> 1;
  return min(get(node * 2, l, mid, ll, rr),
             get(node * 2 + 1, mid + 1, r, ll, rr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  klir();
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> qq(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qq[r].push_back({l, i});
  }
  vector<int> ans(q);
  for (int i = 0; i < n; i++) {
    if (lst[a[i]] >= 0) {
      modify(1, 0, n - 1, lst[a[i]], inf);
    }
    modify(1, 0, n - 1, i, lst[a[i]]);
    lst[a[i]] = i;
    for (auto Q : qq[i]) {
      auto id = get(1, 0, n - 1, Q.first, i);
      if (id.first < Q.first) ans[Q.second] = a[id.second];
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}