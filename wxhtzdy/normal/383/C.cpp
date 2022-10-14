#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 200050;

vector<int> g[N];
int b[N], tin[N], tout[N], tsz, ord[N], dep[N];

void dfs(int u, int p) {
  tin[u] = ++tsz;
  ord[tsz] = u;
  for (int v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  tout[u] = tsz;
}

struct segtree{
  vector<int> st[2], lzy[2];
  segtree(int n) {
    st[0].resize(4 * n);
    st[1].resize(4 * n);
    lzy[0].resize(4 * n);
    lzy[1].resize(4 * n);
  }
  void build(int node, int l, int r) {
    if (l > r) return;
    if (l == r) {
      st[dep[ord[l]] % 2][node] = b[ord[l]];
      return;
    }
    int mid = l + r >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    st[0][node] = st[0][node * 2] + st[0][node * 2 + 1];
    st[1][node] = st[1][node * 2] + st[1][node * 2 + 1];
  }
  void push(int node, int l, int r) {
    st[0][node] += lzy[0][node];
    st[1][node] += lzy[1][node];
    if (l != r) {
      lzy[0][node * 2] += lzy[0][node];
      lzy[0][node * 2 + 1] += lzy[0][node];

      lzy[1][node * 2] += lzy[1][node];
      lzy[1][node * 2 + 1] += lzy[1][node];
    }
    lzy[0][node] = 0;
    lzy[1][node] = 0;
  }
  void update(int node, int l, int r, int ll, int rr, int val, int p) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      lzy[p][node] += val;
      //lzy[p ^ 1][node] += val;
      push(node, l, r);
      return;
    }
    int mid = l + r >> 1;
    update(node * 2, l, mid, ll, rr, val, p);
    update(node * 2 + 1, mid + 1, r, ll, rr, val, p);
    st[0][node] = st[0][node * 2] + st[0][node * 2 + 1];
    st[1][node] = st[1][node * 2] + st[1][node * 2 + 1];
  }
  int get(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) {
      assert(l == r);
      int p = dep[ord[l]] % 2;
      return st[p][node] - st[p ^ 1][node];
    }
    int mid = l + r >> 1;
    return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, qq;
  cin >> n >> qq;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  segtree val(n);
  val.build(1, 1, n);
  while (qq--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      val.update(1, 1, n, tin[x], tout[x], y, dep[x] % 2);
    } else {
      int x;
      cin >> x;
      cout << val.get(1, 1, n, tin[x], tin[x]) << '\n';
    }
  }
}