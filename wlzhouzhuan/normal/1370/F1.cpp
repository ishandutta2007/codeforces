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

const int N = 1005;
vector <int> adj[N];
int n, root, len;

void ask(vector <int> s) {
  printf("? ");
  printf("%d ", s.size());
  for (auto v: s) printf("%d ", v);
  putchar('\n');
  fflush(stdout);
}

int dep[N], fa[N], tag[N];
vector <int> depth[N];
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  ::fa[u] = fa;
  depth[dep[u]].pb(u);
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}

int jumps(int x) {
  while (fa[x] != root) {
    x = fa[x];
  }
  return x;
}
void dfs2(int u, int fa) {
  tag[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs2(v, u);
  }  
}

void solve() {
  n = read();
  for (rint i = 1; i <= n; i++) {
    adj[i].clear(), depth[i - 1].clear();
    dep[i] = fa[i] = 0;
    tag[i] = 0;
  }
  for (rint i = 1; i < n; i++) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  printf("? %d ", n);
  for (rint i = 1; i <= n; i++) printf("%d ", i);
  putchar('\n');
  fflush(stdout);
  scanf("%d%d", &root, &len);
  dfs(root, 0);
  
  int l = (len + 1) / 2, r = *max_element(dep + 1, dep + n + 1) + 1;
  int Lnode, Rnode;
  while (l < r) {
    int mid = l + r >> 1;
    ask(depth[mid]);
    int x, y;
    scanf("%d%d", &x, &y);
    if (y == len) l = mid + 1, Lnode = x; 
    else r = mid;
  }
  
  dfs2(jumps(Lnode), root);
  vector <int> may;
  for (rint i = 1; i <= n; i++) {
    if (!tag[i] && dep[Lnode] + dep[i] == len) {
      may.pb(i);
    }
  }
  ask(may);
  int y;
  scanf("%d%d", &Rnode, &y);
  printf("! %d %d\n", Lnode, Rnode);
  fflush(stdout);
  char win[15];
  scanf("%s", win);
}

int main() {
  dep[0] = -1;
  int T = read();
  while (T--) solve();
  return 0; 
}