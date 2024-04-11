#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n;
int md;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

struct Matrix {
  int a[2][2];

  Matrix(int diag = 1) {
    a[0][0] = diag;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = diag;
  }
};

inline Matrix mul(Matrix &a, Matrix b) {
  Matrix c(0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c.a[i][j] = ((long long)a.a[i][0] * b.a[0][j] + (long long)a.a[i][1] * b.a[1][j]) % md;
    }
  }
  return c;
}

inline Matrix power(Matrix a, long long b) {
  Matrix res(1);
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int s[N], value[N];
long long pos[N];
Matrix tree[N];

void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    tree[x] = mul(tree[x + x], tree[x + x + 1]);
  } else {
    tree[x] = Matrix(0);
    tree[x].a[1][0] = 1;
    tree[x].a[0][1] = s[(l + n - 2) % n];
    tree[x].a[1][1] = s[(l + n - 1) % n];
  }
}

Matrix get(int x, int l, int r, int ll, int rr) {
  if (r < ll || rr < l || ll > rr) {
    return Matrix(1);
  }
  if (ll <= l && r <= rr) {
    return tree[x];
  }
  int y = (l + r) >> 1;
  Matrix res(1);
  if (ll <= y) {
    res = get(x + x, l, y, ll, rr);
  }
  if (rr > y) {
    res = mul(res, get(x + x + 1, y + 1, r, ll, rr));
  }
  return res;
}

map <long long, int> mp;

inline void proceed(Matrix &res, long long pos) {
  Matrix other(0);
  other.a[1][0] = 1;
  if (mp.find(pos - 2) == mp.end()) {
    other.a[0][1] = s[(pos - 2 + n) % n];
  } else {
    other.a[0][1] = mp[pos - 2];
  }
  if (mp.find(pos - 1) == mp.end()) {
    other.a[1][1] = s[(pos - 1 + n) % n];
  } else {
    other.a[1][1] = mp[pos - 1];
  }
  res = mul(res, other);
}

int main() {
  long long k;
  scanf("%I64d %d", &k, &md);
  if (md == 1) {
    printf("%d\n", 0);
    return 0;
  }
  if (k == 0) {
    printf("%d\n", 0 % md);
    return 0;
  }
  if (k == 1) {
    printf("%d\n", 1 % md);
    return 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
    s[i] %= md;
  }
  build(1, 0, n - 1);
  Matrix all = tree[1];
  vector <long long> special;
  int m;
  scanf("%d", &m);
  mp.clear();
  for (int i = 0; i < m; i++) {
    scanf("%I64d %d", pos + i, value + i);
    value[i] %= md;
    special.push_back(pos[i] + 1);
    special.push_back(pos[i] + 2);
    mp[pos[i]] = value[i];
  }
  special.push_back(k);
  sort(special.begin(), special.end());
  special.resize(unique(special.begin(), special.end()) - special.begin());
  while (!special.empty() && special.back() > k) {
    special.pop_back();
  }
  Matrix res(1);
  long long cur = 1;
  for (int id = 0; id < (int)special.size(); id++) {
    long long nxt = special[id];
    long long from = cur + 1;
    long long to = nxt - 1;
    if (from <= to) {
      if (from / n == to / n) {
        res = mul(res, get(1, 0, n - 1, from % n, to % n));
      } else {
        res = mul(res, get(1, 0, n - 1, from % n, n - 1));
        res = mul(res, power(all, to / n - from / n - 1));
        res = mul(res, get(1, 0, n - 1, 0, to % n));
      }
    }
    proceed(res, nxt);
    cur = nxt;
  }
  printf("%d\n", res.a[1][1]);
  return 0;
}