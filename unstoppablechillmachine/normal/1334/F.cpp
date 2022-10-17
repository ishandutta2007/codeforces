#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 5e5 + 10;
int t[4 * N], f[4 * N];

void build(int v, int l, int r, int vl) {
  if (l == r) {
    if (l == 0) {
      t[v] = 0;
    }
    else {
      t[v] = vl;
    }
    return;
  }
  int mid = (l + r) / 2;
  build(2 * v, l, mid, vl);
  build(2 * v + 1, mid + 1, r, vl);
}

void push(int v) {
  if (f[v]) {
    f[2 * v] += f[v];
    f[2 * v + 1] += f[v];
    f[v] = 0;
  }
}

void update(int v, int l, int r, int a, int b, int delta) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    f[v] += delta;
    return;
  }
  push(v);
  int mid = (l + r) / 2;
  update(2 * v, l, mid, a, b, delta);
  update(2 * v + 1, mid + 1, r, a, b, delta);
}

int get(int v, int l, int r, int need) {
  if (l == r) {
    return t[v] + f[v];
  }
  push(v);
  int mid = (l + r) / 2;
  if (need <= mid) {
    return get(2 * v, l, mid, need);
  }
  return get(2 * v + 1, mid + 1, r, need);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int &x : a) {
    cin >> x;
  }
  int sum = 0;
  for (int &x : c) {
    cin >> x;
    sum += x;
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int &x : b) {
    cin >> x;
  }
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[ptr]) {
      ptr++;
      if (ptr == m) {
        break;
      }
    }
  }
  if (ptr < m) {
    cout << "NO\n";
    exit(0);
  }
  build(1, 0, m, -1e18);
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(all(b), a[i]) - b.begin();
    if (c[i] > 0) update(1, 0, m, pos + 1, m, c[i]);
    if (pos < SZ(b) && b[pos] == a[i]) {
      int vl1 = get(1, 0, m, pos + 1), vl2 = get(1, 0, m, pos);
      if (vl2 + c[i] > vl1) {
        update(1, 0, m, pos + 1, pos + 1, vl2 + c[i] - vl1);
      }
    }
  }
  cout << "YES\n";
  cout << sum - get(1, 0, m, m) << '\n';
}