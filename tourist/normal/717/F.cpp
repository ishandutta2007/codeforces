#include <bits/stdc++.h>

using namespace std;

#define add_const ADD_CONST

struct Segment {
  long long sum;
  long long min_odd;
  long long min_even;
  int len;
};

Segment unite(Segment a, Segment b) {
  Segment c;
  c.len = b.len + a.len;
  c.sum = b.sum + ((b.len & 1) ? (-a.sum) : a.sum);
  if (a.len & 1) {
    c.min_even = min(a.min_even, -a.sum + b.min_odd);
    c.min_odd = min(a.min_odd, a.sum + b.min_even);
  } else {
    c.min_even = min(a.min_even, a.sum + b.min_even);
    c.min_odd = min(a.min_odd, -a.sum + b.min_odd);
  }
  return c;
}

const int N = 1234567;

Segment a[N];
int add[N];

void build(int x, int l, int r) {
  a[x].len = r - l + 1;
  a[x].sum = a[x].min_odd = a[x].min_even = 0;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

void add_const(int x, int value) {
  if (a[x].len & 1) {
    a[x].sum += value;
  }
  a[x].min_odd += value;
  add[x] += value;
}

void push(int x) {
  if (add[x] != 0) {
    add_const(x + x, add[x]);
    add_const(x + x + 1, add[x]);
    add[x] = 0;
  }
}

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    add_const(x, v);
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, v);
  }
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, v);
  }
  a[x] = unite(a[x + x], a[x + x + 1]);
}

Segment solve(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return a[x];
  }
  push(x);
  int y = (l + r) >> 1;
  Segment res;
  if (rr <= y) {
    res = solve(x + x, l, y, ll, rr);
  } else {
    if (ll > y) {
      res = solve(x + x + 1, y + 1, r, ll, rr);
    } else {
      res = unite(solve(x + x, l, y, ll, rr), solve(x + x + 1, y + 1, r, ll, rr));
    }
  }
  a[x] = unite(a[x + x], a[x + x + 1]);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  build(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    modify(1, 0, n - 1, i, i, foo);
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int from, to, value;
      scanf("%d %d %d", &from, &to, &value);
      modify(1, 0, n - 1, from, to, value);
    } else {
      int from, to;
      scanf("%d %d", &from, &to);
      Segment res = solve(1, 0, n - 1, from, to);
      printf("%d\n", (res.sum == (res.len & 1) && res.min_odd >= 1 && res.min_even >= 0) ? 1 : 0);
    }
  }
  return 0;
}