#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 50005, M = 100015;

int n, r1, r2, t1, top, v[M], next[M], head[N], fa[N], qhead, qtail, q[N];
bool vis[N];

void bfs(const int st) {
  qhead = 0; qtail = 1; q[1] = st;
  vis[st] = true;
  while (qhead < qtail) {
    int t1 = q[++qhead];
    for (int j = head[t1]; j; j = next[j]) {
      if (!vis[v[j]]) {
        q[++qtail] = v[j];
        vis[v[j]] = true;
        fa[v[j]] = t1;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &r1, &r2);
  for (int i = 1; i <= n; ++i) {
    if (i == r1) continue;
    scanf("%d", &t1);
    ++top; v[top] = i; next[top] = head[t1]; head[t1] = top;
    ++top; v[top] = t1; next[top] = head[i]; head[i] = top;
  }
  bfs(r2);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == r2) continue;
    ++cnt;
    printf("%d", fa[i]);
    if (cnt == n - 1) printf("\n"); else printf(" ");
  }
  return 0;
}