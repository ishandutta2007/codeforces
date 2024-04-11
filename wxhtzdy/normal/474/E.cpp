#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5;
const int M = 4 * N + 5;

struct node {
  int val = 0, pos = -1;
};

node seg[M];

node comb(node x, node y) {
  if (x.val < y.val) {
    return y;
  } else {
    return x;
  }
}

void update(int node, int l, int r, int pos, int val, int i) {
  if (l > r || r < pos || l > pos) {
    return;
  }
  if (l == r) {
    if (seg[node].val < val) {
      seg[node].val = val;
      seg[node].pos = i;
    }
    return;
  }
  int mid = l + r >> 1;
  update(node * 2, l, mid, pos, val, i);
  update(node * 2 + 1, mid + 1, r, pos, val, i);
  seg[node] = comb(seg[node * 2], seg[node * 2 + 1]);
}

node get(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) {
    return seg[M - 1];
  }
  if (ll <= l && r <= rr) {
    return seg[node];
  }
  int mid = l + r >> 1;
  return comb(get(node * 2, l, mid, ll, rr), get(node * 2 + 1, mid + 1, r, ll, rr));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  vector<int> all;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    all.push_back(a[i]);
    all.push_back(a[i] - d);
    all.push_back(a[i] + d);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  map<int, int> val;
  for (int i = 0; i < (int) all.size(); i++) {
    val[all[i]] = i;
  }
  vector<int> dp(n), jump(n);
  for (int i = 0; i < n; i++) {
    node L = get(1, 0, (int) val.size(), 0, val[a[i] - d]);
    node R = get(1, 0, (int) val.size(), val[a[i] + d], (int) all.size());
    node cur = comb(L, R);
    dp[i] = cur.val + 1;
    jump[i] = cur.pos;
    //cout << cur.val << " " << cur.pos << '\n';
    update(1, 0, (int) all.size(), val[a[i]], dp[i], i);
  }
  int start = 0;
  for (int i = 0; i < n; i++) if (dp[i] >= dp[start]) start = i;
  vector<int> ans;
  while (start >= 0) {
    ans.push_back(start);
    start = jump[start];
  }
  cout << (int) ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i + 1 << " ";
  }
  cout << '\n';
  return 0;
}