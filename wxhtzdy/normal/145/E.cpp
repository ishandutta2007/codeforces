#include <bits/stdc++.h>

using namespace std;

const int N = 1000050;
const int M = N * 4;

int n, qq, a[N];
int st[M][4], ls[M], rs[M], root, T, lzy[M];

void pull(int node) {
  st[node][0] = st[ls[node]][0] + st[rs[node]][0];
  st[node][1] = st[ls[node]][1] + st[rs[node]][1];
  st[node][2] = max({st[ls[node]][2] + st[rs[node]][1], st[ls[node]][0] + st[rs[node]][2], st[ls[node]][0] + st[rs[node]][1]});
  st[node][3] = max({st[ls[node]][3] + st[rs[node]][0], st[ls[node]][1] + st[rs[node]][3], st[ls[node]][1] + st[rs[node]][0]});
}

void push(int node) {
  if (lzy[node]) {
    swap(st[node][0], st[node][1]);
    swap(st[node][2], st[node][3]);
    lzy[ls[node]] ^= 1;
    lzy[rs[node]] ^= 1;
    lzy[node] = 0;
  }
}

void build(int& node, int l, int r) {
  assert(l <= r);
  node = ++T;
  if (l == r) {
    st[node][(a[l] == 4 ? 0 : 1)]++;
    return;
  }
  int mid = l + r >> 1;
  build(ls[node], l, mid);
  build(rs[node], mid + 1, r);
  pull(node);
}

void update(int node, int l, int r, int ll, int rr) {
  push(node);
  if (l > r || r < ll || l > rr) {
    return;
  }
  if (ll <= l && r <= rr) {
    lzy[node] ^= 1;
    push(node);
    return;
  }
  int mid = l + r >> 1;
  update(ls[node], l, mid, ll, rr);
  update(rs[node], mid + 1, r, ll, rr);
  pull(node);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> qq;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    a[i] = (int) (s[i] - '0');
  }
  build(root, 0, n - 1);
  while (qq--) {
    string foo;
    cin >> foo;
    if (foo == "switch") {
      int L, R;
      cin >> L >> R;
      --L; --R;
      update(root, 0, n - 1, L, R);
    } else {
      cout << max({st[root][0], st[root][1], st[root][2]}) << '\n';
    }
  }
  return 0;
}