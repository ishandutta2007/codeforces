#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 2e5 + 5;
const int M = 4 * N;

vector<int> g[N];
int a[N], tin[N], tout[N], tsz, ord[N];
int st[M], lzy[M];

void dfs(int u, int p) {
  tin[u] = ++tsz;
  ord[tsz] = u;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = tsz;
}

void build(int node, int l, int r) {
  if (l > r) return;
  if (l == r) {
    st[node] = a[ord[l]];
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

void push(int node, int l, int r) {
  if (lzy[node]) {
    st[node] = r - l + 1 - st[node];
    if (l != r) {
      lzy[node * 2] ^= 1;
      lzy[node * 2 + 1] ^= 1;
    }
    lzy[node] = 0;
  }
}

void update(int node, int l, int r, int ll, int rr) {
  push(node, l, r);
  if (l > r || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    lzy[node] ^= 1;
    push(node, l, r);
    return;
  }
  int mid = l + r >> 1;
  update(node * 2, l, mid, ll, rr);
  update(node * 2 + 1, mid + 1, r, ll, rr);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

int get(int node, int l, int r, int ll, int rr) {
  push(node, l, r);
  if (l > r || l > rr || r < ll) return 0;
  if (ll <= l && r <= rr) return st[node];
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    g[p - 1].push_back(i);
  }
  for (int i = 0; i < n; i++)  cin >> a[i];
  dfs(0, -1);
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    string type;
    cin >> type;
    if (type == "pow") {
      int v;
      cin >> v;
      --v;
      update(1, 1, n, tin[v], tout[v]);
    } else {
      int v;
      cin >> v;
      --v;
      cout << get(1, 1, n, tin[v], tout[v]) << '\n';
    }
  }
}