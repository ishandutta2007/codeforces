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
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
inline int read() {
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

const int N = 400005;
const int inf = 1e9;


int a[N], b[N], w[N], ans[N];
int n, m, q;

//struct LCT {
  int ch[N][2], fa[N], rev[N];
  int sz[N], mn[N];
  bool nroot(int x) {
    return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
  }
  void pushup(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
    if (w[mn[ch[x][0]]] < w[mn[ch[x][1]]]) mn[x] = mn[ch[x][0]];
    else mn[x] = mn[ch[x][1]];
    if (w[x] < w[mn[x]]) mn[x] = x; 
  }
  void pushrev(int x) {
    if (!x) return ;
    rev[x] ^= 1, swap(ch[x][0], ch[x][1]);
  } 
  void pushdown(int x) {
    if (rev[x]) rev[x] = 0, pushrev(ch[x][0]), pushrev(ch[x][1]);
  }
  void Rotate(int x) {
    int y = fa[x], z = fa[y], k = ch[y][1] == x;
    if (nroot(y)) ch[z][ch[z][1] == y] = x;
    ch[y][k] = ch[x][k ^ 1];
    if (ch[x][k ^ 1]) fa[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y, fa[y] = x, fa[x] = z;
    pushup(y), pushup(x);
  }
  int stk[N], top;
  void Splay(int x) {
    int t = x;
    stk[++top] = x;
    while (nroot(x)) stk[++top] = x = fa[x];
    while (top) pushdown(stk[top--]);
    x = t; 
    while (nroot(x)) {
      int y = fa[x], z = fa[y];
      if (nroot(y)) Rotate((ch[z][0] == y) ^ (ch[y][0] == x) ? x : y);
      Rotate(x);
    }
  }
  void access(int x) {
    for (int y = 0; x; y = x, x = fa[x]) {
      Splay(x), ch[x][1] = y, pushup(x);
    }
  }
  void makeroot(int x) {
    access(x), Splay(x), pushrev(x);
  }
  int findroot(int x) {
    access(x), Splay(x);
    while (ch[x][0]) pushdown(x), x = ch[x][0];
    Splay(x); return x;
  }
  void link(int x, int y) {
    makeroot(x);
    if (findroot(y) != x) fa[x] = y;
  }
  void cut(int x, int y) {
    makeroot(x);
    if (findroot(y) == x && fa[y] == x && !ch[y][0]) {
      fa[y] = ch[x][1] = 0;
      pushup(x);
    }
  }
  void split(int x, int y) {
    makeroot(x), access(y), Splay(y);
  }
  bool check(int x, int y) {
    makeroot(x);
    return findroot(y) == x;
  }
//} lct;

bool vis[N];
set<int> s;

int main() {
  memset(ans, 0x3f, sizeof(ans));
  w[0] = inf;
  n = read(), m = read(), q = read();
  rep(i, 1, n) w[i] = inf;
  rep(i, 1, m) a[i + n] = read(), b[i + n] = read(), w[i + n] = i;
  rep(i, 1, n + m) sz[i] = 1;
  rep(i, 1, m) {
    if (!check(a[i + n], b[i + n])) {
      link(a[i + n], i + n), link(i + n, b[i + n]);
    } else {
      split(a[i + n], b[i + n]);
      int x = mn[b[i + n]];
      
//      assert(lct.sz[b[i + n]] & 1);
      
      if (((sz[b[i + n]] + 1) / 2) & 1) s.insert(x);
      cut(a[x], x), cut(x, b[x]), vis[x] = 0;
      link(a[i + n], i + n), link(i + n, b[i + n]);
    }
    vis[i + n] = 1;
  }
  int r = 0;
  rep(i, 1, m) {
    if (r < i) {
      ++r;
      if (vis[r + n]) cut(a[r + n], r + n), cut(r + n, b[r + n]);
      else s.erase(r + n);
      vis[r + n] = 0;
    }
    while (r < m && s.size()) {
      ++r;
      if (vis[r + n]) cut(a[r + n], r + n), cut(r + n, b[r + n]);
      else s.erase(r + n);
      vis[r + n] = 0;
    }
//    printf("i = %d, ", i); for (auto v: s) printf("%d ", v); puts("");
    if (s.size()) break;
    ans[i] = r - 1;
//    printf("ans[%d] = %d\n", i, ans[i]);
    w[i + n] = inf / 3;
    if (!check(a[i + n], b[i + n])) {
      link(a[i + n], i + n), link(i + n, b[i + n]);
    } else {
      split(a[i + n], b[i + n]);
      int x = mn[b[i + n]];
      
//      assert(lct.sz[b[i + n]] & 1);
      
      if (((sz[b[i + n]] + 1) / 2) & 1) s.insert(x);
      cut(a[x], x), cut(x, b[x]), vis[x] = 0;
      link(a[i + n], i + n), link(i + n, b[i + n]);
    }
    vis[i + n] = 1;
  }
  while (q--) {
    int l = read(), r = read();
    puts(r <= ans[l] ? "YES" : "NO");
  }
  return 0;
}