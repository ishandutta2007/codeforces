#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

const int N = 200010;

int kw = 0, order[N];
int pos[N], to[N];
int pv[N];
vector <int> g[N];

void dfs(int v) {
  order[++kw] = v;
  pos[v] = kw;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    dfs(u);
  }
  to[v] = kw;
}

int sum[5 * N], coeff[5 * N];

void build(int x, int l, int r) {
  coeff[x] = 1;
  sum[x] = 0;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

inline void push(int x) {
  if (coeff[x] != 1) {
    coeff[x + x] = mul(coeff[x + x], coeff[x]);
    coeff[x + x + 1] = mul(coeff[x + x + 1], coeff[x]);
    coeff[x] = 1;
  }
}

inline void gather(int x) {
  sum[x] = mul(sum[x + x], coeff[x + x]);
  add(sum[x], mul(sum[x + x + 1], coeff[x + x + 1]));
}

void modify_pt(int x, int l, int r, int p, int v) {
  if (l == r) {
    coeff[x] = 1;
    sum[x] = v;
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (p <= y) {
    modify_pt(x + x, l, y, p, v);
  } else {
    modify_pt(x + x + 1, y + 1, r, p, v);
  }
  gather(x);
}

void modify_seg(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    coeff[x] = mul(coeff[x], v);
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify_seg(x + x, l, y, ll, rr, v);
  }
  if (rr > y) {
    modify_seg(x + x + 1, y + 1, r, ll, rr, v);
  }
  gather(x);
}

int get_sum(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return mul(sum[x], coeff[x]);
  }
  push(x);
  int y = (l + r) >> 1;
  int res = 0;
  if (ll <= y) {
    add(res, get_sum(x + x, l, y, ll, rr));
  }
  if (rr > y) {
    add(res, get_sum(x + x + 1, y + 1, r, ll, rr));
  }
  gather(x);
  return res;
}

int n, fenw[N];

void modify_fenw(int x, int v) {
  while (x <= n) {
    fenw[x] = mul(fenw[x], v);
    x = (x | (x - 1)) + 1;
  }
}

int get_product(int x) {
  int res = 1;
  while (x > 0) {
    res = mul(res, fenw[x]);
    x &= x - 1;
  }
  return res;
}

int v[N];
int op[N], query[N];
int cnt[N], summ[N];

int main() {
  int tt;
  scanf("%d %d", v + 0, &tt);
  n = 1;
  pv[0] = -1;
  for (int i = 0; i < tt; i++) {
    scanf("%d", op + i);
    if (op[i] == 1) {
      query[i] = n;
      scanf("%d %d", pv + n, v + n);
      pv[n]--;
      n++;
    } else {
      scanf("%d", query + i);
      query[i]--;
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    g[pv[i]].push_back(i);
  }
  dfs(0);
  for (int i = 1; i <= n; i++) {
    fenw[i] = 1;
  }
  build(1, 1, n);
  cnt[0] = 1;
  summ[0] = v[0];
  modify_pt(1, 1, n, 1, v[0]);
  for (int qq = 0; qq < tt; qq++) {
    int c_op = op[qq];
    int i = query[qq];
    if (c_op == 1) {
      int pr = pv[i];
      int by = get_product(pos[pr]);
      cnt[pr]++;
      add(summ[pr], v[i]);
      int frac = mul(cnt[pr], inv(cnt[pr] - 1));
      modify_seg(1, 1, n, pos[pr], to[pr], frac);
      modify_fenw(pos[pr], frac);
      modify_fenw(to[pr] + 1, inv(frac));
      cnt[i] = 1;
      summ[i] = v[i];
      modify_pt(1, 1, n, pos[i], mul(v[i], mul(by, frac)));
    } else {
      int by = (i == 0 ? 1 : inv(get_product(pos[pv[i]])));
      printf("%d\n", mul(by, get_sum(1, 1, n, pos[i], to[i])));
    }
  }
  return 0;
}