#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int INF = 1e9 + 10;
vector<int> f;

void push(int v) {
  if (f[v] != INF) {
    f[2 * v] = f[v];
    f[2 * v + 1] = f[v];
    f[v] = INF;
  }
}

void update(int v, int l, int r, int a, int b, int val) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    f[v] = val;
    return;
  }
  int mid = (l + r) / 2;
  push(v);
  update(2 * v, l, mid, a, b, val);
  update(2 * v + 1, mid + 1, r, a, b, val);
}

int get(int v, int l, int r, int need) {
  if (l == r) {
    return f[v];
  }
  int mid = (l + r) / 2;
  push(v);
  if (need <= mid) {
    return get(2 * v, l, mid, need);
  }
  return get(2 * v + 1, mid + 1, r, need);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  f.resize(4 * n + 10, INF);
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> ps2(q), ps(q);
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, pos2, len;
      cin >> pos >> pos2 >> len;
      ps[i] = pos;
      ps2[i] = pos2;
      update(1, 1, n, pos2, pos2 + len - 1, i);
    }
    else {
      int pos;
      cin >> pos;
      int id = get(1, 1, n, pos);
      //cout << i << ' ' << id << '\n';
      if (id == INF) {
        cout << b[pos] << '\n';
      }
      else {
        cout << a[ps[id] + (pos - ps2[id])] << '\n';
      }
    }
  }
}