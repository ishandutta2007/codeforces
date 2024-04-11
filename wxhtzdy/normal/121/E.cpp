/**
 *    author:  milos
 *    created: 31.07.2021 19:29:24       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;

struct node {
  int x, y;
  node() {}
  node(int _x, int _y) {
    x = _x; y = _y;
  }
  node operator+ (node other) {
    if (x < other.x) return node(x, y);
    if (x > other.x) return other;
    return node(x, other.y + y);
  }
} st[N * 4];

int a[N];      
int lzy[4 * N];
vector<int> lucky;

bool is_lucky(int n) {
  while (n > 0) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}

void push(int node, int l, int r) {
  st[node].x -= lzy[node];
  if (l != r) {
    lzy[node * 2] += lzy[node];
    lzy[node * 2 + 1] += lzy[node];
  } else {
    a[l] += lzy[node];
  }
  lzy[node] = 0;  
}

void build(int node, int l, int r) {
  if (l == r) {
    st[node].x = 4 - a[l];
    st[node].y = 1;
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

int get(int node, int l, int r, int ll, int rr) {
  push(node, l, r);
  if (l > r || l > rr || r < ll) return 0;
  if (ll <= l && r <= rr) return (st[node].x == 0 ? st[node].y : 0);
  int mid = l + r >> 1;
  return get(node * 2, l, mid, ll, rr) + get(node * 2 + 1, mid + 1, r, ll, rr);
}

void modify(int node, int l, int r, int ll, int rr, int val) {
  push(node, l, r);
  if (l > r || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    lzy[node] += val;
    push(node, l, r);
    return;
  }
  int mid = l + r >> 1;
  modify(node * 2, l, mid, ll, rr, val);
  modify(node * 2 + 1, mid + 1, r, ll, rr, val);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

void walk(int node, int l, int r) {
  if (l > r) return;
  push(node, l, r);
  if (st[node].x >= 0) return;
  if (l == r) {
    for (int x : lucky) {
      if (x >= a[l]) {
        st[node].x = x - a[l];
        st[node].y = 1;
        break;
      }
    }
    return;
  }
  int mid = l + r >> 1;
  walk(node * 2, l, mid);
  walk(node * 2 + 1, mid + 1, r);
  st[node] = st[node * 2] + st[node * 2 + 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];  
  }       
  build(1, 0, n - 1);
  for (int i = 1; i <= 50000; i++) {
    if (is_lucky(i)) {
      lucky.push_back(i);
    }
  }
  walk(1, 0, n - 1);
  while (q--) {
    string foo;
    cin >> foo;
    if (foo == "count") {
      int L, R;
      cin >> L >> R;
      --L, --R;
      cout << get(1, 0, n - 1, L, R) << '\n'; 
    } else {
      int L, R, x;
      cin >> L >> R >> x;
      --L, --R;
      modify(1, 0, n - 1, L, R, x);
      walk(1, 0, n - 1);
    }
  }
  return 0;
}