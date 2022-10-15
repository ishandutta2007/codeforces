// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
 
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
 
const int N = 200005;
struct Q {
  int o, u, v;
} q[N];
vector <int> adj[N];
int deg[N], dep[N];
int n, m, t;
 
int flag = 0;
 
void topo() {
  queue <int> q;
  for (int i = 1; i <= n; i++) {
    if (!deg[i]) {
      q.push(i);
      dep[i] = 1;
    }
  }
  int Nums = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    Nums++;
    for (auto v: adj[u]) {
      if (--deg[v] == 0) {
        q.push(v);
        dep[v] = dep[u] + 1;
      }
    }
  }
  if (Nums != n) flag = 1;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0); 
  int T;
  cin >> T;
  while (T--) {
    t = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      dep[i] = deg[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int types, u, v;
      cin >> types >> u >> v;
      q[++t] = {types, u, v};
      if (types == 1) {
        adj[u].pb(v);
        deg[v]++;
      }
    }
    flag = 0;
    topo();
    if (flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
      if (q[i].o) {
        cout << q[i].u << ' ' << q[i].v << '\n';
        continue;
      }
      int u = q[i].u, v = q[i].v;
      if (dep[u] ^ dep[v]) {
        if (dep[u] > dep[v]) swap(u, v);
        cout << u << ' ' << v << '\n';
      } else {
        if (u > v) swap(u, v);
        cout << u << ' ' << v << '\n';
      }
    }
  }
  return 0;
}