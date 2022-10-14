#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = 20;
const int M = 4 * N;

int p[N], a[N], b[N];
int id[N], lst[N], nxt[N][L], prv[N], st[M];
vector<int> pos[N];
bool was[N];

void build(int node, int l, int r) {
  if (l > r) {
    st[node] = 1e9;
    return;
  }
  if (l == r) {
    st[node] = b[l];
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
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
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    prv[p[i]] = p[(i + 1) % n];
  }
  fill(lst, lst + N, -1);
  fill(b, b + N, 1e9);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < L; j++) {
      nxt[i][j] = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    if (id[prv[a[i]]] < (int) pos[prv[a[i]]].size()) {
      nxt[i][0] = pos[prv[a[i]]][id[prv[a[i]]]];
    } else {
      nxt[i][0] = -1;
    }
    id[a[i]]++;
  }
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 1; j < L; j++) {
      if (nxt[i][j - 1] >= 0) {
        nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    b[i] = i;
    for (int j = L - 1; j >= 0; j--) {
      if (b[i] >= 0 && (n - 1) & (1 << j)) {
        b[i] = nxt[b[i]][j];
      }
    }
    if (b[i] == -1) {
      b[i] = 1e9;
    }
  }
  build(1, 0, m - 1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int mn = get(1, 0, m - 1, l, r);
    cout << (mn <= r ? 1 : 0);
  }
  cout << '\n';
  return 0;
}