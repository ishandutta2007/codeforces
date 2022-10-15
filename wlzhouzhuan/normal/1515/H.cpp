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

const int N = 200005;
const int B = 20;
const int K = (1 << B) - 1;

int a[N], n, q;


int ls[60 * N], rs[60 * N], tot, rt;
int Vand[60 * N], Vor[60 * N], siz[60 * N], lazy[60 * N];

void pushup(int u) {
  Vand[u] = Vand[ls[u]] | Vand[rs[u]];
  Vor[u] = Vor[ls[u]] | Vor[rs[u]];
  siz[u] = siz[ls[u]] + siz[rs[u]]; 
}
void pushxor(int dep, int u, int val) {
  if (!u) return ;
//  printf("pushxor %d %d %d\n", dep, u, val);
  if (val >> (dep - 1) & 1) swap(ls[u], rs[u]);
  int tmpand = Vand[u], tmpor = Vor[u];
  Vand[u] = (tmpand & (val ^ K)) | (tmpor & val);
  Vor[u] = (tmpor & (val ^ K)) | (tmpand & val);
  lazy[u] ^= val;
}
void pushdown(int dep, int u) {
  if (lazy[u]) {
    pushxor(dep - 1, ls[u], lazy[u]), pushxor(dep - 1, rs[u], lazy[u]);
    lazy[u] = 0;
  }
}
void ins(int dep, int &u, int l, int r, int val) {
  if (!u) u = ++tot;
  if (dep == 0) {
    Vand[u] = val ^ K;
    Vor[u] = val;
    siz[u] = 1;
    return ;
  }
  int mid = l + r >> 1;
  if (val >> (dep - 1) & 1) ins(dep - 1, rs[u], l, mid, val);
  else ins(dep - 1, ls[u], mid + 1, r, val);
//  printf("%d %d\n", u, val);
  pushup(u);
}
void split(int dep, int &u, int &v, int l, int r, int ql, int qr) {
//  printf("split %d %d %d %d %d %d %d\n", u, v, dep, l, r, ql, qr); 
  if (!u || qr < l || ql > r) {
    v = 0;
    return ;
  }
  if (ql <= l && r <= qr) {
    v = u, u = 0;
    return ;
  }
  pushdown(dep, u), v = ++tot;
  int mid = l + r >> 1;
  split(dep - 1, ls[u], ls[v], l, mid, ql, qr);
  split(dep - 1, rs[u], rs[v], mid + 1, r, ql, qr);
  pushup(u), pushup(v);
//  printf("ls[%d]=%d,rs[%d]=%d,ls[%d]=%d,rs[%d]=%d\n",u,ls[u],u,rs[u],v,ls[v],v,rs[v]);
//  printf(">>> %d %d %d %d\n",Vand[u],Vor[u],Vand[v],Vor[v]);
}
void merge(int dep, int &x, int &y) {
//  printf("merge %d %d %d\n", x, y, dep);
  if (!x) {
    x = y;
    return ;
  }
  if (!y || dep == 0) return ;
  pushdown(dep, x), pushdown(dep, y);
  merge(dep - 1, ls[x], ls[y]);
  merge(dep - 1, rs[x], rs[y]);
  pushup(x);
}
void update_or(int dep, int u, int l, int r, int x) {
  if (!u) return ;
  int add = Vand[u] & x;
  if ((add & Vor[u]) == 0) {
    pushxor(dep, u, add);
    return ;
  }
  pushdown(dep, u);
  int mid = l + r >> 1;
  if (x >> (dep - 1) & 1) {
    pushxor(dep - 1, ls[u], 1 << dep - 1);
    merge(dep - 1, rs[u], ls[u]);
    ls[u] = 0;
  }
  update_or(dep - 1, ls[u], l, mid, x);
  update_or(dep - 1, rs[u], mid + 1, r, x);
  pushup(u);
//  printf("update_or %d %d %d %d %d\n",u,ls[u],rs[u],Vand[u],Vor[u]);
}
int query(int dep, int u, int l, int r, int ql, int qr) {
//  printf("query %d %d %d %d %d %d\n",dep,u,l,r,ql,qr);
  if (!u || qr < l || ql > r) return 0;
  if (ql <= l && r <= qr) return siz[u];
  pushdown(dep, u);
  int mid = l + r >> 1, ans = 0;
  ans += query(dep - 1, ls[u], l, mid, ql, qr);
  ans += query(dep - 1, rs[u], mid + 1, r, ql, qr);
  return ans;
}

int main() {
  n = read(), q = read();
  rep(i, 1, n) {
    a[i] = read();
    ins(20, rt, 0, K, a[i]);
  }
//  printf("tot = %d\n", tot);
//      for(int i=1;i<=tot;i++){
//        printf("info[%d]: %d %d %d\n",i,Vand[i],Vor[i],siz[i]);
//      }
//      return 0;
  while (q--) {
    int opt = read(), l = read(), r = read(), x, y = 0;
    if (opt == 4) {
      print(query(20, rt, 0, K, l, r), '\n');
    } else {
      x = read();
      split(20, rt, y, 0, K, l, r);
//      printf("modify rt = %d\n", y);
      if (opt == 1) pushxor(20, y, K), update_or(20, y, 0, K, x ^ K), pushxor(20, y, K); 
      else if (opt == 2) update_or(20, y, 0, K, x);
      else pushxor(20, y, x);
      merge(20, rt, y);
//      printf("tot = %d\n", tot);
//      for(int i=1;i<=tot;i++){
//        printf("info[%d]: %d %d %d\n",i,Vand[i],Vor[i],siz[i]);
//      }
//      system("pause");
    }
  }
  return 0;
}