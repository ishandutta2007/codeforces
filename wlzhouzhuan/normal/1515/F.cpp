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

const int N = 300005;
ll a[N];
int n, m, x;

vector<pii> adj[N];
int ans[N], l, r;
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  for (auto it: adj[u]) {
    int v = it.fir, id = it.sec;
    if (vis[v]) continue;
    dfs(v);
    if (a[u] + a[v] >= x) {
      a[u] += a[v] - x;
      ans[l++] = id;
    } else {
      ans[r--] = id;
    }
  }
}

int main() {
  n = read(), m = read(), x = read();
  ll qwq = 0;
  rep(i, 1, n) a[i] = read(), qwq += a[i];
  if (qwq < 1ll * x * (n - 1)) return puts("NO"), 0;
  rep(i, 1, m) {
    int u = read(), v = read();
    adj[u].pb({v, i}), adj[v].pb({u, i});
  }
  l = 1, r = n - 1;
  dfs(1);
  puts("YES");
  rep(i, 1, n - 1) print(ans[i], '\n');
  return 0;
}