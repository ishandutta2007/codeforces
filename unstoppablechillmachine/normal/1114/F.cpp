#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int N = 4e5 + 10;
const int MX = 62;
int pr[MX];
int in[310], calc[310][11];
vector<vector<pair<int, int>>> gt(310);
inline bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

inline int mult(int a, int b) {
  return (a * b) % MOD;
}

int b_pow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return mult(a, b_pow(a, b - 1));
  }
  int c = b_pow(a, b >> 1);
  return mult(c, c);
}

inline int inv(int x) {
  return b_pow(x, MOD - 2);
}

struct ST {
  vector<pair<int, int>> t, f;
  vector<int> arr;
  vector<vector<pair<int, int>>> gt;
  ST(int n, vector<int> &_arr, vector<vector<pair<int, int>>> &_gt) {
    t.resize(4 * n + 10);
    f.resize(4 * n + 10, {1, 0});
    arr = _arr;
    gt = _gt;
    build(1, 1, n);
  }
  inline void addT(int v, pair<int, int> it, int len) {
    t[v].F = mult(t[v].F, b_pow(calc[pr[it.F]][it.S], len));
    t[v].S |= 1ll << it.F;
  }
  inline void addF(int v, pair<int, int> it) {
    f[v].F = mult(f[v].F, calc[pr[it.F]][it.S]);
    f[v].S |= 1ll << it.F;
  }
  pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return {mult(a.F, b.F), a.S | b.S};
  }
  void build(int v, int l, int r) {
    if (l == r) {
      t[v] = {1, 0};
      for (auto it : gt[arr[l]]) {
        addT(v, it, 1);
      }
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
  }
  void push(int v, int len1, int len2) {
    if (f[v] == make_pair(1ll, 0ll)) {
      return;
    }
    f[2 * v] = merge(f[2 * v], f[v]);
    f[2 * v + 1] = merge(f[2 * v + 1], f[v]);
    t[2 * v] = merge(t[2 * v], {b_pow(f[v].F, len1), f[v].S});
    t[2 * v + 1] = merge(t[2 * v + 1], {b_pow(f[v].F, len2), f[v].S});
    f[v] = {1, 0};
  }
  void update(int v, int l, int r, int a, int b, int x) {
    if (l > b || r < a) {
      return;
    }
    if (l >= a && r <= b) {
      for (auto it : gt[x]) {
        addT(v, it, r - l + 1);
        addF(v, it);
      }
      return;
    }
    int mid = (l + r) / 2;
    push(v, mid - l + 1, r - mid);
    update(2 * v, l, mid, a, b, x);
    update(2 * v + 1, mid + 1, r, a, b, x);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
  }
  pair<int, int> get(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
      return {1, 0};
    }
    if (l >= a && r <= b) {
      return t[v];
    }
    int mid = (l + r) / 2;
    push(v, mid - l + 1, r - mid);
    return merge(get(2 * v, l, mid, a, b), get(2 * v + 1, mid + 1, r, a, b));
  }
};

void source() {
  for (int i = 1; i <= 300; i++) {
    int cur = 1;
    for (int j = 0; j <= 8; j++) {
      calc[i][j] = cur;
      cur *= i;
    }
  }
  int cnt = 0;
  for (int i = 2; i <= 300; i++) {
    if (prime(i)) {
      pr[cnt++] = i;
    }
  }
  for (int i = 0; i <= 300; i++) {
    in[i] = b_pow(i, MOD - 2);
  }
  for (int i = 2; i <= 300; i++) {
    int cur = i;
    for (int j = 0; j < cnt; j++) {
      int cc = 0;
      while (cur % pr[j] == 0) {
        cc++;
        cur /= pr[j];
      }
      if (cc) {
        gt[i].pb({j, cc});
      }
    }
    assert(cur == 1);
  }
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  ST tree(n, arr, gt);
  for (int i = 0; i < m; i++) {
    string type;
    cin >> type;
    if (type[0] == 'M') {
      int l, r, x;
      cin >> l >> r >> x;
      tree.update(1, 1, n, l, r, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      pair<int, int> res = tree.get(1, 1, n, l, r);
      for (int j = 0; j < 62; j++) {
        if ((res.S >> j) & 1) {
          res.F = mult(mult(res.F, in[pr[j]]), pr[j] - 1);
        }
      }
      cout << res.F << '\n';
    }
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}