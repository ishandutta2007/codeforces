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

const int N = 1000005;
vector <int> adj[N];
int n, m,  Q;
int a[N];

queue <int> q;
int dis[N], vis[N];
void bfs(int st) {
  mset(dis, 0x3f);
  dis[st] = 0;
  while (!q.empty())  q.pop();
  q.push(st);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v: adj[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        vis[v] = 0;
        q.push(v);
      } else if (dis[v] == dis[u] + 1) {
        vis[v] = 1;
      }
    }
  }
} 

int main() {
  scanf("%d%d", &n, &m);
  for (rint i = 1; i <= m; i++) {
    int u = read(), v = read();
    adj[v].pb(u);
  }
  Q = read();
  for (rint i = 1; i <= Q; i++) a[i] = read();
  bfs(a[Q]);
  
  int ans1 = 0, ans2 = 0;
  for (rint i = 1; i < Q; i++) {
    if (dis[a[i]] != dis[a[i + 1]] + 1) {
      ans1++;
      ans2++;
    }
    if (dis[a[i]] == dis[a[i + 1]] + 1 && vis[a[i]]) {
      ans2++;
    }
  }
  printf("%d %d\n", ans1, ans2);
}