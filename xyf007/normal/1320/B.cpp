#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct edge {
  int to, nxt;
  edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e1[200001], e2[200001];
int n, m, k, p[200001], E1, head1[200001], E2, head2[200001], dis[200001],
    vis[200001];
void add1(int f, int t) {
  e1[E1].to = t;
  e1[E1].nxt = head1[f];
  head1[f] = E1++;
}
void add2(int f, int t) {
  e2[E2].to = t;
  e2[E2].nxt = head2[f];
  head2[f] = E2++;
}
void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head2[u]; i != -1; i = e2[i].nxt) {
      int v = e2[i].to;
      if (vis[v]) continue;
      dis[v] = dis[u] + 1;
      vis[v] = 1;
      q.push(v);
    }
  }
}
int main(int argc, char const *argv[]) {
  scanf("%d%d", &n, &m);
  memset(head1, -1, sizeof(head1));
  memset(head2, -1, sizeof(head2));
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add1(u, v);
    add2(v, u);
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
  bfs(p[k]);
  int minn = 0, maxx = 0;
  for (int i = 1; i < k; i++) {
    bool f = 0;
    int minnn = 2e9;
    for (int j = head1[p[i]]; j != -1; j = e1[j].nxt) {
      int v = e1[j].to;
      if (dis[v] < minnn) {
        minnn = dis[v];
        f = 0;
      } else if (dis[v] == minnn) {
        f = 1;
      }
    }
    if (dis[p[i + 1]] > minnn) {
      minn++;
      maxx++;
    } else if (f) {
      maxx++;
    }
  }
  printf("%d %d", minn, maxx);
  return 0;
}