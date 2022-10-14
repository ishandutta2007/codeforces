#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int dep[N], tin[N], tout[N], curr;

void dfs(int u, int p) {
  tin[u] = ++curr;
  for (int v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  tout[u] = curr;
}

const int M = 25 * N;

int root[M], ls[M], rs[M], st[M], nxt;

void modify(int p, int& c, int ll, int rr, int x, int y) {
  c = ++nxt; ls[c] = ls[p]; rs[c] = rs[p]; st[c] = min(st[p], y);
  if (ll == rr) return;
  int mid = ll + rr >> 1;
  if (x <= mid) modify(ls[p], ls[c], ll, mid, x, y);
  else modify(rs[p], rs[c], mid + 1, rr, x, y);
}

int get(int c, int ll, int rr, int ql, int qr) {
  if (ll > rr || ll > qr || rr < ql) return 1e9;
  if (ql <= ll && rr <= qr) return st[c];
  int mid = ll + rr >> 1;
  return min(get(ls[c], ll, mid, ql, qr), get(rs[c], mid + 1, rr, ql, qr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  --r;
  dfs(r, r);
  vector<vector<int>> all(n);
  for (int i = 0; i < n; i++) {
    all[dep[i]].push_back(i);
  }
  for (int i = 0; i < M; i++) {
    st[i] = 1e9;
  }
  for (int i = 0; i < n; i++) {
    if (i) root[i] = root[i - 1];
    for (int j : all[i]) {
      modify(root[i], root[i], 1, curr, tin[j], a[j]);
    }
  }
  int qq;
  cin >> qq;
  int last = 0;
  while (qq--) {
    int p, q;
    cin >> p >> q;
    int x = (p + last) % n;
    int k = (q + last) % n;
    last = get(root[min(n - 1, dep[x] + k)], 1, curr, tin[x], tout[x]);
    cout << last << '\n';
  }
  return 0;
}