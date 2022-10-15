// Author: wlzhouzhuan
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

const int N = 5005;
const int mod = 998244353;

vector<int> adj[N];
int n, K;

void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod; 
}
int dep[N], sz[N], dp[N][N], tmp[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  sz[u] = 1;
  dp[u][0] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    for (int j = 0; j <= sz[u] + sz[v]; j++) tmp[j] = 0;
    // 
    for (int j = 0; j <= sz[u] && j <= K; j++) {
      for (int k = 0; k <= sz[v] && k <= K; k++) {
        add(tmp[j], 1ll * dp[u][j] * dp[v][k] % mod);
      }
    } 
    // 
    for (int j = 0; j <= sz[u] && j <= K; j++) {
      for (int k = 0; k <= sz[v] && k + 1 + j <= K; k++) {
        add(tmp[max(j, k + 1)], 1ll * dp[u][j] * dp[v][k] % mod);
      }
    }
    sz[u] += sz[v];
    for (int j = 0; j <= sz[u]; j++) dp[u][j] = tmp[j];
  }
}

int main() {
  n = read(), K = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0);
  int ans = 0;
  for (int i = 0; i <= K; i++) add(ans, dp[1][i]);
  print(ans, '\n');
  return 0;
}