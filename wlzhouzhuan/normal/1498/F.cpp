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

const int N = 100005;
vector<int> adj[N];
int a[N], f[N][45], g[N][45];
int n, k;

void dfs1(int u, int fa) {
  f[u][0] = a[u];
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    for (int j = 0; j < k; j++) f[u][(j + 1) % k] ^= f[v][j]; 
  }
}
int tmp[45];
void dfs2(int u, int fa) {
  memcpy(g[u], f[u], sizeof(f[u]));
  if (fa) {
    memcpy(tmp, g[fa], sizeof(g[fa]));
    for (int j = 0; j < k; j++) tmp[(j + 1) % k] ^= f[u][j];
    for (int j = 0; j < k; j++) g[u][(j + 1) % k] ^= tmp[j];
  }
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs2(v, u);
  } 
}
int main() {
  n = read(), k = 2 * read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++) a[i] = read();
  dfs1(1, 0);
  int t = 0;
//  for (int i = 0; i < k; i++) printf("f[%d][%d] = %d\n", 1, i, f[1][i]);
  dfs2(1, 0);
  k /= 2;
  for (int i = 1; i <= n; i++) {
    int coef = 0;
    for (int j = k; j < 2 * k; j++) {
      coef ^= g[i][j];
    }
    if (coef) putchar('1'); else putchar('0');
    putchar(' ');
  }
}