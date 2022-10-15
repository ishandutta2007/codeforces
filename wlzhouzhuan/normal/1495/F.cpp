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

ll a[N], b[N], c[N], dis[N];
int stk[N], top;
int p[N], n, q;

int fa[N][21], dep[N];
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--) {
    if (dep[fa[u][i]] >= dep[v]) {
      u = fa[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (fa[u][i] ^ fa[v][i]) {
      u = fa[u][i], v = fa[v][i];
    }
  }
  return fa[u][0];
}
ll dist(int u, int v) {
  return dis[u] + dis[v] - 2ll * dis[lca(u, v)];
}

ll ans;
int vis[N], tag[N];
set<int> s;

void ins(int x) {
  auto it = s.insert(x).first;
  int L = *(--it); it++; it++;
  if (it == s.end()) it = s.begin();
  int R = *it;
  ans += dist(L, x) + dist(x, R) - dist(L, R);
}
void del(int x) {
  auto it = s.find(x);
  int L = *(--it); it++; it++;
  if (it == s.end()) it = s.begin();
  int R = *it;
  ans -= dist(L, x) + dist(x, R) - dist(L, R);
  s.erase(x);
}

int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    p[i] = read();
    while (top && p[stk[top]] < p[i]) top--;
    fa[i][0] = stk[top], dep[i] = dep[stk[top]] + 1;
    stk[++top] = i;
    for (int j = 1; j <= 20; j++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    c[i] += a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = read();
    c[i] -= b[i];
    c[fa[i][0]] += b[i];
  }
  for (int i = n; i >= 1; i--) {
    dis[i] += c[i];
    dis[fa[i][0]] += min(0ll, dis[i]);
//    dis[i] = max(0ll, dis[i]);
    dis[i] -= min(0ll, dis[i]);
  }
  dis[0] += c[0];
//  cerr << dis[0] << '\n';
  for (int i = 1; i <= n; i++) dis[i] += dis[fa[i][0]];
  tag[0]++, s.insert(0);
  
  while (q--) {
    int x = read();
    if (!vis[x]) {
      vis[x] = 1;
      if (++tag[fa[x][0]] == 1) ins(fa[x][0]);
    } else {
      vis[x] = 0;
      if (--tag[fa[x][0]] == 0) del(fa[x][0]);
    }
    print(ans / 2 + dis[0], '\n');
  }
  return 0;
}