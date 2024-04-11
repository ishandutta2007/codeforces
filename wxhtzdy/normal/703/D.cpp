#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int M = 4 * N;

int st[M];

void modify(int node, int l, int r, int pos, int val) {
  if (l > r || r < pos || pos < l) return;
  if (l == r) {
    st[node] = val;
    return;  
  }
  int mid = l + r >> 1;
  if (pos <= mid) modify(node * 2, l, mid, pos, val);
  else modify(node * 2 + 1, mid + 1, r, pos, val);
  st[node] = st[node * 2] ^ st[node * 2 + 1];
}

int get(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) return 0;
  if (ll <= l && r <= rr) return st[node];
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr) ^ get(node * 2 + 1, mid + 1, r, ll, rr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] ^ a[i];
  }
  int qq;
  cin >> qq;
  vector<vector<pair<int, int>>> q(n + 1);
  for (int i = 1; i <= qq; i++) {
    int l, r;
    cin >> l >> r;
    q[r].push_back({l, i});
  }
  vector<int> ans(qq + 1);
  map<int, int> lst;
  for (int i = 1; i <= n; i++) {
    if (lst[a[i]] != 0) {
      modify(1, 1, n, lst[a[i]], 0);
    }
    lst[a[i]] = i;
    modify(1, 1, n, i, a[i]);
    for (auto c : q[i]) {
      int l = c.first, r = i;
      int px = pref[r] ^ pref[l - 1];
      ans[c.second] = px ^ get(1, 1, n, l, r);
    }
  }
  for (int i = 1; i <= qq; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}