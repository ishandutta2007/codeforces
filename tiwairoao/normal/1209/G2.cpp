#include <bits/stdc++.h>

const int N = 200000;

int f[N + 5];
namespace segt{
  #define lch (x << 1)
  #define rch (x << 1 | 1)
  
  const int S = (N << 2);
  
  struct type{
    int mn, lm, rm, m, s;
    friend type operator + (const type &a, const type &b) {
      type c; c.mn = std::min(a.mn, b.mn), c.m = std::max(a.m, b.m);
      if (a.mn < b.mn) {
        c.lm = a.lm, c.rm = std::max(a.rm, b.m), c.s = a.s;
      } else if (a.mn > b.mn) {
        c.lm = std::max(a.m, b.lm), c.rm = b.rm, c.s = b.s;
      } else {
        c.lm = a.lm, c.rm = b.rm, c.s = a.s + b.s + std::max(a.rm, b.lm);
      }
      return c;
    }
  }t[S + 5];
  
  int le[S + 5], ri[S + 5], tag[S + 5];
  void addtag(int x, int k) {tag[x] += k, t[x].mn += k;}
  void pushup(int x) {t[x] = t[lch] + t[rch];}
  void pushdown(int x) {
    if (tag[x]) addtag(lch, tag[x]), addtag(rch, tag[x]), tag[x] = 0;
  }
  void build(int x, int l, int r) {
    le[x] = l, ri[x] = r, t[x] = (type){0, 0, 0, 0, 0};
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lch, l, m), build(rch, m + 1, r);
  }
  void add(int x, int l, int r, int d) {
    if (r < le[x] || l > ri[x]) return;
    if (l <= le[x] && ri[x] <= r) {addtag(x, d); return;}
    pushdown(x), add(lch, l, r, d), add(rch, l, r, d), pushup(x);
  }
  void update(int x, int p) {
    if (le[x] == ri[x]) {
      t[x].lm = f[p], t[x].rm = f[p + 1], t[x].m = std::max(f[p], f[p + 1]);
      return;
    }
    int m = (le[x] + ri[x]) >> 1;
    pushdown(x), update(p <= m ? lch : rch, p), pushup(x);
  }
}

std::set<int>st[N + 5];
int a[N + 5], n, q;

void clear(int x) {
  if (st[x].empty()) return;
  
  int lc = *st[x].begin();
  segt::add(1, lc, (*st[x].rbegin()) - 1, -1);
  f[lc] = 0, segt::update(1, lc - 1), segt::update(1, lc);
}
void calc(int x) {
  if (st[x].empty()) return;
  
  int lc = *st[x].begin();
  segt::add(1, lc, (*st[x].rbegin()) - 1, 1);
  f[lc] = (int)st[x].size(), segt::update(1, lc - 1), segt::update(1, lc);
}
void erase(int i) {
  int x = a[i]; clear(x), st[x].erase(i), calc(x);  
}
void insert(int i) {
  int x = a[i]; clear(x), st[x].insert(i), calc(x);  
}

int main() {
  scanf("%d%d", &n, &q);
  
  segt::build(1, 0, n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), insert(i);
  printf("%d\n", n - segt::t[1].s);
  
  for (int t = 1, i, x; t <= q; t++) {
    scanf("%d%d", &i, &x);
    erase(i), a[i] = x, insert(i);
    printf("%d\n", n - segt::t[1].s);
  }
}