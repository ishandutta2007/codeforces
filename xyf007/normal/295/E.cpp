#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
constexpr int kInf = 1e9;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int ls, rs, cnt;
  long long sum, ans;
  Node(int ls = 0, int rs = 0, int cnt = 0, long long sum = 0LL,
       long long ans = 0LL)
      : ls(ls), rs(rs), cnt(cnt), sum(sum), ans(ans) {}
} t[8000001];
int n, m, tot = 1, a[100001];
void Merge(Node &s, const Node &l, const Node &r) {
  s.cnt = l.cnt + r.cnt;
  s.sum = l.sum + r.sum;
  s.ans = l.ans + r.ans + l.cnt * r.sum - r.cnt * l.sum;
}
void Pushup(int x) { Merge(t[x], t[t[x].ls], t[t[x].rs]); }
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    t[x].cnt += v;
    t[x].sum += v * l;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) {
    if (!t[x].ls) t[x].ls = ++tot;
    Modify(l, mid, p, v, t[x].ls);
  } else {
    if (!t[x].rs) t[x].rs = ++tot;
    Modify(mid + 1, r, p, v, t[x].rs);
  }
  Pushup(x);
}
Node Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x];
  int mid = (l + r) >> 1;
  if (R <= mid) {
    return Query(L, R, l, mid, t[x].ls);
  } else if (L > mid) {
    return Query(L, R, mid + 1, r, t[x].rs);
  } else {
    Node ans;
    Merge(ans, Query(L, R, l, mid, t[x].ls), Query(L, R, mid + 1, r, t[x].rs));
    return ans;
  }
}
int main(int argc, char const *argv[]) {
  Read(n);
  for (int i = 1; i <= n; i++) {
    Read(a[i]);
    Modify(-kInf, kInf, a[i], 1, 1);
  }
  Read(m);
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    Read(op, x, y);
    if (op == 1) {
      Modify(-kInf, kInf, a[x], -1, 1);
      Modify(-kInf, kInf, a[x] += y, 1, 1);
    } else {
      std::printf("%lld\n", Query(x, y, -kInf, kInf, 1).ans);
    }
  }
  return 0;
}