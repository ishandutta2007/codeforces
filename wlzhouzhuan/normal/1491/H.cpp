// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define SZ(a) ((int)(a.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
const int B = 355;

int n, q, L[N / B + 5], R[N / B + 5], be[N], sz;

int a[N], go[N], lzy[N];
int fa(int u) {
  return max(1, a[u] - lzy[be[u]]);
}
int jump(int u) {
  if (lzy[be[u]] < B) return go[u];
  else return fa(u);
}
void rebuild(int t) {
  for (int i = L[t]; i <= R[t]; i++) {
    int to = fa(i);
    if (to < L[t]) go[i] = to;
    else go[i] = go[to];
//    printf("go[%d] = %d\n", i, go[i]);
  }
}
void update(int l, int r, int x) {
  int bl = be[l], br = be[r];
  if (bl == br) {
    for (int i = l; i <= r; i++) a[i] = max(1, a[i] - x);
    rebuild(bl);
  } else {
    for (int i = l; i <= R[bl]; i++) a[i] = max(1, a[i] - x);
    rebuild(bl);
    for (int i = bl + 1; i <= br - 1; i++) {
      lzy[i] = min(lzy[i] + x, n);
      if (lzy[i] < B) rebuild(i);
    }
    for (int i = L[br]; i <= r; i++) a[i] = max(1, a[i] - x);
    rebuild(br);
  }
}
int LCA(int u, int v) {
  if (u == v) return u;
  int lstu = u, lstv = v;
  while (u != v) {
    if (u < v) swap(u, v), swap(lstu, lstv);
    lstu = u, u = jump(u);
  }
  if (u && be[lstu] != be[lstv]) return u;
//  printf("u = %d, v = %d, lstu = %d, lstv = %d\n", u, v, lstu, lstv);
  while (lstu != lstv) {
    if (lstu < lstv) swap(lstu, lstv);
    lstu = fa(lstu);
  }
  return lstu;
}
int main() {
  n = read(), q = read();
  for (int i = 2; i <= n; i++) a[i] = read();
  for (int l = 1; l <= n; l += B) {
    int r = min(l + B - 1, n);
    sz++, L[sz] = l, R[sz] = r;
    for (int i = l; i <= r; i++) be[i] = sz;
  }
  for (int i = 1; i <= sz; i++) rebuild(i);
  while (q--) {
    int opt = read();
    if (opt == 1) {
      int l = read(), r = read(), x = read();
      update(l, r, x);
    } else {
      int u = read(), v = read();
      print(LCA(u, v), '\n');
    }
  }
  return 0;
}