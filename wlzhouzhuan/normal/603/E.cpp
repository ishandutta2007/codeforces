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

const int N = 300005;

pii a[N];
int _U[N], _V[N], _W[N];
int ans[N], n, m;

int f[N], sz[N], tmpx[N], tmpy[N], comp, top;
int find(int x) {
  return f[x] == x ? x : find(f[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return ;
  if (sz[x] > sz[y]) swap(x, y);
  comp -= sz[x] & 1, comp -= sz[y] & 1;
  f[x] = y, sz[y] += sz[x];
  comp += sz[y] & 1;
  tmpx[++top] = x, tmpy[top] = y;
}
void rollback(int aim) {
  while (top > aim) {
    comp -= sz[tmpy[top]] & 1;
    sz[tmpy[top]] -= sz[tmpx[top]];
    comp += sz[tmpy[top]] & 1, comp += sz[tmpx[top]] & 1; 
    f[tmpx[top]] = tmpx[top];
    top--;
  }
}

void cdq(int l, int r, int x, int y) {
  if (l > r) return ;
  int mid = l + r >> 1, aim = top;
  //printf("When l = %d, r = %d, aim = %d\n", l, r, aim);
  for (int i = l; i <= mid; i++) {
    if (make_pair(_W[i], i) < a[x]) {
      merge(_U[i], _V[i]);
    }
  }
  for (int i = x; i <= y; i++) {
    int id = a[i].sec;
    if (id <= mid) {
      merge(_U[id], _V[id]);
      if (!comp) {
        ans[mid] = i;
        break;
      }
    }
  }
  rollback(aim);
  if (!ans[mid]) {
    for (int i = l; i <= mid; i++) {
      if (make_pair(_W[i], i) < a[x]) {
        merge(_U[i], _V[i]);
      }
    }
    cdq(mid + 1, r, x, y);
    rollback(aim);
    return ;
  }
  //printf("mid = %d, ans = %d\n", mid, ans[mid]);
  for (int i = x; i < ans[mid]; i++) {
    int id = a[i].sec;
    if (id < l) {
      merge(_U[id], _V[id]);
    }
  }
  cdq(l, mid - 1, ans[mid], y);
  rollback(aim);
  for (int i = l; i <= mid; i++) {
    if (make_pair(_W[i], i) < a[x]) {
      merge(_U[i], _V[i]);
    }
  }
  cdq(mid + 1, r, x, ans[mid]);
  rollback(aim);
}

int main() {
  n = read(), m = read();
  comp = n;
  for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  for (int i = 1; i <= m; i++) {
    _U[i] = read(), _V[i] = read(), _W[i] = read();
    a[i] = make_pair(_W[i], i);
  }
  a[0].fir = -1;
  sort(a + 1, a + m + 1);
  //for (int i = 1; i <= m; i++) printf("edge[%d] = %d\n", i, a[i].fir);
  cdq(1, m, 1, m);
  for (int i = 1; i <= m; i++) print(a[ans[i]].fir, '\n');
  return 0;
}