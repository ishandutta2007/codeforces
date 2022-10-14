#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct segtree {
  vector<int> st, lzy;
  segtree(int n) {
    st.resize(4 * n);
    lzy.resize(4 * n);
  }
  void push(int node, int l, int r) {
    if (lzy[node]) {
      st[node] = lzy[node];
      if (l != r) {
        lzy[node * 2] = lzy[node];
        lzy[node * 2 + 1] = lzy[node];
      }
      lzy[node] = 0;
    }
  }
  void update(int node, int l, int r, int ll, int rr, int val) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
      lzy[node] = val;
      push(node, l, r);
      return;
    }
    int mid = l + r >> 1;
    update(node * 2, l, mid, ll, rr, val);
    update(node * 2 + 1, mid + 1, r, ll, rr, val);
    st[node] = max(st[node * 2], st[node * 2 + 1]);
  }
  int get(int node, int l, int r, int ll, int rr) {
    push(node, l, r);
    if (l > r || l > rr || r < ll) return 0;
    if (ll <= l && r <= rr) return st[node];
    int mid = l + r >> 1;
    return max(get(node * 2, l, mid, ll, rr), get(node * 2 + 1, mid + 1, r, ll, rr));
  }
};

const int N = 500050;

vector<int> g[N];
int tin[N], tout[N], tsz;

void dfs(int u, int p) {
  tin[u] = ++tsz;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = tsz;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  segtree water(n), removed(n);
  int qq;
  cin >> qq;
  for (int i = 1; i <= qq; i++) {
    int op, v;
    cin >> op >> v;
    if (op == 1) {
      water.update(1, 1, n, tin[v], tout[v], i);
    }
    if (op == 2) {
      removed.update(1, 1, n, tin[v], tin[v], i);
    }
    if (op == 3) {
      int a = water.get(1, 1, n, tin[v], tin[v]);
      int b = removed.get(1, 1, n, tin[v], tout[v]);
      cout << (a > b ? 1 : 0) << '\n';
    }
  }
}