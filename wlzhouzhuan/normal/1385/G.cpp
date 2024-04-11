// Author: wlzhouzhuan
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

#define x first
#define y second
 
const int N = 300010;
 
bool oddCyc;
vector <pii> pos[N];
bitset <N> vis, _fixed, flip;
vector <int> g[N], nodes[N], cnt[2];
int t, n, a[5][N], cur, comp[N], color[N];
 
void go (int u) {
  comp[u] = cur, nodes[cur].emplace_back(u);
  for (int v : g[u]) if (!comp[v]) go(v); 
}
 
void dfs (int u, int col = 0) {
  if (oddCyc) return;
  vis[u] = 1, color[u] = col;
  for (int x : nodes[u]) cnt[col].emplace_back(x); 
  for (int v : g[u]) {
    if (!vis[v]) dfs(v, col ^ 1);
    else if (color[v] == col) {
      oddCyc = 1;
      return;
    }
  }
}
 
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      comp[i] = vis[i] = flip[i] = 0;
      pos[i].clear(), g[i].clear(), nodes[i].clear(); 
    }
    for (int i = 1; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", a[i] + j);
        pos[a[i][j]].emplace_back(i, j);
      }
    }
    bool bad = 0;
    for (int i = 1; i <= n; ++i) {
      if (pos[i].size() != 2) {
        bad = 1;
        break;
      }
    }
    if (bad) {
      puts("-1");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      _fixed[i] = (a[1][i] == a[2][i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (_fixed[i]) continue;
      int x = a[1][i], y = a[2][i];
      {
        if (pos[x][0] == pii(1, i)) {
          swap(pos[x][0], pos[x][1]);
        }
        if (pos[x][0].x != 1) {
          int j = pos[x][0].y;
          g[i].emplace_back(j);
        }
      } {
        if (pos[y][0] == pii(2, i)) {
          swap(pos[y][0], pos[y][1]);
        }
        if (pos[y][0].x != 2) {
          int j = pos[y][0].y;
          g[i].emplace_back(j);
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout << i << " --> ";
    //   for (int j : g[i]) cout << j << " "; cout << '\n';
    // }
    cur = 0;
    for (int i = 1; i <= n; ++i) {
      if (_fixed[i] or comp[i]) continue;
      ++cur, go(i);
    }
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      if (_fixed[i]) continue;
      int x = a[1][i], y = a[2][i];
      {
        if (pos[x][0] == pii(1, i)) {
          swap(pos[x][0], pos[x][1]);
        }
        if (pos[x][0].x == 1) {
          int j = pos[x][0].y;
          if (comp[i] == comp[j]) {
            bad = 1;
            break;
          }
          g[comp[i]].emplace_back(comp[j]);
        }
      } {
        if (pos[y][0] == pii(2, i)) {
          swap(pos[y][0], pos[y][1]);
        }
        if (pos[y][0].x == 2) {
          int j = pos[y][0].y;
          if (comp[i] == comp[j]) {
            bad = 1;
            break;
          }
          g[comp[i]].emplace_back(comp[j]);
        }
      }
    }
    if (bad) {
      puts("-1");
      continue;
    }
    oddCyc = 0;
    int tot = 0;
    for (int i = 1; i <= cur; ++i) {
      if (vis[i]) continue;
      cnt[0].clear(), cnt[1].clear(), dfs(i);
      if (oddCyc) break;
      if (cnt[0].size() < cnt[1].size()) {
        for (int x : cnt[0]) ++tot, flip[x] = 1;
      } else {
        for (int x : cnt[1]) ++tot, flip[x] = 1;
      }
    }
    if (oddCyc) {
      puts("-1");
      continue;
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
      if (flip[i]) printf("%d ", i);
    }
    puts("");
  }
  return 0;
}