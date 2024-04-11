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

const int N = 3e5 + 10;
int t[N];
void upd_fen(int v, int delta) {
  for (; v < N; v += v & (-v)) {
    t[v] += delta;
  }
}

int get_fen(int v) {
  int rez = 0;
  for (; v > 0; v -= v & (-v)) {
    rez += t[v];
  }
  return rez;
}

int get_sum(int l, int r) {
  return get_fen(r) - get_fen(l - 1);
}

const int INF = 1e9 + 10;
pair<int, int> tree[4 * N];
int f[4 * N], val[N];

void build(int v, int l, int r) {
  if (l == r) {
    tree[v] = {val[l], l};
    return;
  }
  int mid = (l + r) / 2;
  build(2 * v, l, mid);
  build(2 * v + 1, mid + 1, r);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

void push(int v) {
  if (f[v]) {
    f[2 * v] += f[v];
    f[2 * v + 1] += f[v];
    tree[2 * v].F += f[v];
    tree[2 * v + 1].F += f[v];
    f[v] = 0;
  }
}

void update(int v, int l, int r, int a, int b, int delta) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    tree[v].F += delta;
    f[v] += delta;
    return; 
  }
  push(v);
  int mid = (l + r) / 2;
  update(2 * v, l, mid, a, b, delta);
  update(2 * v + 1, mid + 1, r, a, b, delta);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

pair<int, int> get_min(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return {INF, INF};
  }
  if (l >= a && r <= b) {
    return tree[v];
  }
  push(v);
  int mid = (l + r) / 2;
  return min(get_min(2 * v, l, mid, a, b), get_min(2 * v + 1, mid + 1, r, a, b));
}

int ans[N];
vector<pair<int, int>> que[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    que[x].pb({y, i});
    /*int balance = 0;
    for (int j = 1 + x; j <= n - y; j++) {
      if (j - a[j] >= 0 && j - a[j] <= balance) {
        balance++;
      }
    } 
    cout << balance << '\n';*/
  }
  int balance = 0;
  for (int i = 1; i <= n; i++) {
    if (i - a[i] >= 0 && i - a[i] <= balance) {
      val[i] = balance - (i - a[i]);
      balance++;
      upd_fen(i, 1);
    }
    else {
      val[i] = INF;
    }
  } 
  build(1, 1, n);
  for (int i = 0; i < n; i++) {
    if (i && get_sum(i, i) == 1) {
      upd_fen(i, -1);
      update(1, 1, n, i + 1, n, -1);
      for (;;) {
        pair<int, int> cur = get_min(1, 1, n, i + 1, n);
        if (cur.F >= 0) {
          break;
        }
        upd_fen(cur.S, -1);
        update(1, 1, n, cur.S + 1, n, -1);
        update(1, 1, n, cur.S, cur.S, INF);
      }
    }
    for (auto it : que[i]) {
      ans[it.S] = get_sum(i + 1, n - it.F);
    }
  } 
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}