#include <bits/stdc++.h>

using namespace std;

#define real REAL

const int N = 200010;

const int BLOCK = 250;

int m;
int from[N], to[N], res[N];
pair <int, int> ev[N];
int real[N], a[N];
int id[N];

inline bool cmp(int x, int y) {
  int u = from[x] / BLOCK;
  int v = from[y] / BLOCK;
  if (u != v) {
    return u < v;
  }
  return to[x] < to[y];
}

int a11[N], a12[N], a13[N];
int a21[N], a22[N], a23[N];

void build(int x, int l, int r) {
  a11[x] = 1; a12[x] = 0; a13[x] = 0;
  a21[x] = 0; a22[x] = 1; a23[x] = 0;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

void modify(int x, int l, int r, int pos, int action) {
  if (l == r) {
    if (action == 1) {
      a11[x] = 1; a12[x] = 1; a13[x] = real[pos];
      a21[x] = 1; a22[x] = 0; a23[x] = 0;
    } else {
      a11[x] = 1; a12[x] = 0; a13[x] = 0;
      a21[x] = 0; a22[x] = 1; a23[x] = 0;
    }
    return;
  }
  int y = (l + r) >> 1;
  if (pos <= y) {
    modify(x + x, l, y, pos, action);
  } else {
    modify(x + x + 1, y + 1, r, pos, action);
  }
  // gather
  a11[x] = (a11[x + x] * a11[x + x + 1] + a12[x + x] * a21[x + x + 1]) % m;
  a12[x] = (a11[x + x] * a12[x + x + 1] + a12[x + x] * a22[x + x + 1]) % m;
  a21[x] = (a21[x + x] * a11[x + x + 1] + a22[x + x] * a21[x + x + 1]) % m;
  a22[x] = (a21[x + x] * a12[x + x + 1] + a22[x + x] * a22[x + x + 1]) % m;

  a13[x] = (a11[x + x] * a13[x + x + 1] + a12[x + x] * a23[x + x + 1] + a13[x + x]) % m;
  a23[x] = (a21[x + x] * a13[x + x + 1] + a22[x + x] * a23[x + x + 1] + a23[x + x]) % m;
}

int t;
int have[N];
int OPS;

void add(int what) {
  if (have[what] == 0) {
    OPS++;
    modify(1, 0, t - 1, what, 1);
  }
  have[what]++;
}

void del(int what) {
  have[what]--;
  if (have[what] == 0) {
    OPS++;
    modify(1, 0, t - 1, what, 0);
  }
}

int main() {
  int n;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ev[i].first);
    ev[i].second = i;
  }
  sort(ev, ev + n);
  t = -1;
  for (int i = 0; i < n; i++) {
    if (i == 0 || ev[i].first != ev[i - 1].first) {
      t++;
      real[t] = ev[i].first % m;
    }
    a[ev[i].second] = t;
  }
  t++;
  for (int i = 0; i < t; i++) {
    have[i] = 0;
  }
  build(1, 0, t - 1);
  int tt;
  scanf("%d", &tt);
  for (int qq = 0; qq < tt; qq++) {
    scanf("%d %d", from + qq, to + qq);
    from[qq]--; to[qq]--;
    res[qq] = 0;
    id[qq] = qq;
  }
  sort(id, id + tt, cmp);
  int ll = from[0], rr = from[0] - 1;
  OPS = 0;
  for (int qq = 0; qq < tt; qq++) {
    while (rr > to[id[qq]]) {
      del(a[rr]);
      rr--;
    }
    while (ll < from[id[qq]]) {
      del(a[ll]);
      ll++;
    }
    while (rr < to[id[qq]]) {
      rr++;
      add(a[rr]);
    }
    while (ll > from[id[qq]]) {
      ll--;
      add(a[ll]);
    }
    res[id[qq]] = a13[1];
//    if ((qq + 1) % 500 == 0) cerr << qq+1 << " processed, OPS = " << OPS << endl;
  }
  for (int qq = 0; qq < tt; qq++) {
    printf("%d\n", (res[qq] % m + m) % m);
  }
//  cerr << clock() << " ms" << endl;
  return 0;
}