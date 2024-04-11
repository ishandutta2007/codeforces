#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 1e5 + 5;
const int M = 4 * N;
const int MX = 1000;

int n, m, a[N];
vector<int> g[N];
int lid[N], rid[N], tsz, ord[N];
bitset<MX> st[M];
int lzy[M];

void dfs(int u, int p) {
  lid[u] = ++tsz;
  ord[tsz] = u;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  rid[u] = tsz;
}

void build(int node, int l, int r) {
  if (l > r) return;
  if (l == r) {
    st[node].set(a[ord[l]], true);
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] | st[node * 2 + 1];
}

void push(int node, int l, int r) {
  lzy[node] %= m;
  if (!lzy[node]) return;
  st[node] = (st[node] << lzy[node]) | (st[node] >> (m - lzy[node]));
  if (l != r) {
    lzy[node * 2] += lzy[node];
    lzy[node * 2 + 1] += lzy[node];
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
  st[node] = st[node * 2] | st[node * 2 + 1];
}

bitset<MX> res;

void get(int node, int l, int r, int ll, int rr) {
  push(node, l, r);
  if (l > r || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    res |= st[node];
    return;
  }
  int mid = l + r >> 1;
  get(node * 2, l, mid, ll, rr);
  get(node * 2 + 1, mid + 1, r, ll, rr);
  st[node] = st[node * 2] | st[node * 2 + 1];
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= m;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bitset<MX> p;
  vector<bool> was(m, false);
  for (int i = 2; i < m; i++) {
    if (!was[i]) {
      p.set(i, true);
      for (int j = i + i; j < m; j += i) {
        was[j] = true;
      }
    }
  }
  dfs(1, 0);
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int foo;
    cin >> foo;
    if (foo == 1) {
      int v, x;
      cin >> v >> x;
      x %= m;
      update(1, 1, n, lid[v], rid[v], x);
    } else {
      int v;
      cin >> v;
      res = 0;
      get(1, 1, n, lid[v], rid[v]);
      res &= p;
      cout << res.count() << '\n';
    }
  }
}