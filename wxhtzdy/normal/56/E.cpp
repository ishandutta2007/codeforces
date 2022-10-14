#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;
const int M = 2 * N;

int st[M];

void update(int node, int l, int r, int p, int val) {
  if (l > r || l > p || r < p) {
    st[node] = 1e9;
    return;
  }
  if (l == r) {
    st[node] = val;
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    update(node * 2, l, mid, p, val);
  } else {
    update(node * 2 + 1, mid + 1, r, p, val);
  }
  st[node] = min(st[node * 2], st[node * 2 + 1]);
}

int get(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) return 1e9;
  if (ll <= l && r <= rr) return st[node];
  int mid = l + r >> 1;
  return min(get(node * 2, l, mid, ll, rr), get(node * 2 + 1, mid + 1, r, ll, rr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < M; i++) st[i] = 1e9;
  int n;
  cin >> n;
  vector<int> x(n), h(n);
  vector<int> xs;
  int mn = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
    mn = min(mn, x[i]);
  }
  for (int i = 0; i < n; i++) {
    x[i] += mn;
  }
  for (int i = 0; i < n; i++) {
    xs.push_back(x[i]);
    xs.push_back(x[i] + h[i] - 1);
  }
  sort(xs.begin(), xs.end());
  map<int, int> val;
  int z = 0;
  for (int i = 0; i < (int) xs.size(); i++) {
    if (i && xs[i] != xs[i - 1]) z++;
    val[xs[i]] = z;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return x[i] > x[j];
  });
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    l[ord[i]] = get(1, 0, (int) xs.size() - 1, val[x[ord[i]]], val[x[ord[i]] + h[ord[i]] - 1]);
    if (l[ord[i]] == 1e9) l[ord[i]] = i;
    update(1, 0, (int) xs.size() - 1, val[x[ord[i]]], l[ord[i]]);
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[ord[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << p[i] - l[i] + 1;
  }
  return 0;
}