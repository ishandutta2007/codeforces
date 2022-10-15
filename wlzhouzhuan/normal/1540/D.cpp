// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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
const int inf = 1e9;
const int B = 200;

int L[N / B + 3], R[N / B + 3];
int a[N], be[N], n, q;

// f[i][j]:  i  +=j  [f[i][j],f[i][j+1]) 
// f[i][j]  
int c[N], f[N / B + 3][B + 1];
#define ls (u << 1)
#define rs (u << 1 | 1)
int mn[N << 2], pos[N << 2], tag[N << 2]; 
inline void pushup(int u) {
  if (mn[ls] <= mn[rs]) mn[u] = mn[ls], pos[u] = pos[ls];
  else mn[u] = mn[rs], pos[u] = pos[rs]; 
}
inline void pushtag(int u, int dlt) {
  mn[u] += dlt, tag[u] += dlt;
}
inline void pushdown(int u) {
  if (tag[u]) {
    pushtag(ls, tag[u]), pushtag(rs, tag[u]);
    tag[u] = 0;
  }
}
void build(int u, int l, int r) {
  if (l == r) {
    mn[u] = c[l], pos[u] = l;
    return ;
  }
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    pushtag(u, -1);
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) update(ls, l, mid, ql, qr);
  if (qr > mid) update(rs, mid + 1, r, ql, qr);
  pushup(u);
}
void ban(int u, int l, int r, int pos) {
  if (l == r) {
    mn[u] = inf;
    return ;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (pos <= mid) ban(ls, l, mid, pos);
  else ban(rs, mid + 1, r, pos);
  pushup(u);
} 

void rebuild(int id, int l, int r) {
  int len = r - l + 1;
  for (int j = l; j <= r; j++) c[j - l + 1] = a[j];
  memset(mn, 0, 16 * len);
  memset(pos, 0, 16 * len);
  memset(tag, 0, 16 * len);
  
  build(1, 1, len);
  for (int j = 1; j <= len; j++) {
    f[id][j] = max(f[id][j - 1], mn[1]);
    int who = pos[1];
    if (who != len) update(1, 1, len, who + 1, len);
    ban(1, 1, len, who);
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = i - read(), be[i] = (i - 1) / B + 1;
  for (int l = 1, r = B, id = 1; l <= n; l += B, r += B, id++) {
    r = min(r, n), L[id] = l, R[id] = r;
    rebuild(id, l, r);
  }
  q = read();
  while (q--) {
    int opt = read(), x = read();
    if (opt == 1) {
      int t = read();
      a[x] = x - t;
      rebuild(be[x], L[be[x]], R[be[x]]);
    } else {
      int now = a[x];
      for (int i = x + 1; i <= R[be[x]]; i++) {
        if (now >= a[i]) ++now;
      } 
//      printf("after now = %d\n", now);
      for (int i = be[x] + 1; i <= be[n]; i++) {
        int pos = upper_bound(f[i] + 1, f[i] + (R[i] - L[i] + 1) + 1, now) - f[i];
        now += pos - 1;
//        printf("after block (%d, %d), now = %d\n", L[i], R[i], now);
//        for (int j = 1; j <= R[i] - L[i] + 1; j++) printf("f[%d][%d] = %d\n", i, j, f[i][j]);
//        puts("-----");
      }
      print(now, '\n');
//      system("pause");
    }
  }
  return 0;
}