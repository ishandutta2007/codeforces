#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int N = 100005, M = 100005 * 4, INF = 2000000000;

int n, m, k, top, t1, t2, t3, v[M], head[N], next[M], l[M], dis[N], qhead, qtail, q[N + 5], tmp[M];
bool inque[N];

map<int, int> tr[N];

int main() {
  scanf("%d %d", &n, &m);
  top = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &t1, &t2, &t3);
    ++top; v[top] = t2; next[top] = head[t1]; head[t1] = top; l[top] = t3;
    ++top; v[top] = t1; next[top] = head[t2]; head[t2] = top; l[top] = t3;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    tr[i].clear();
    if (k > 0) {
      for (int j = 1; j <= k; ++j) {
        scanf("%d", &tmp[j]);
      }
      tr[i][tmp[k]] = tmp[k] + 1;
      for (int j = k - 1; j > 0; --j) {
        if (tmp[j] + 1 == tmp[j + 1]) {
          tr[i][tmp[j]] = tr[i][tmp[j + 1]];
        } else {
          tr[i][tmp[j]] = tmp[j] + 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    dis[i] = INF;
    inque[i] = false;
  }
  dis[1] = (tr[1].count(0) ? tr[1][0] : 0); inque[1] = true;
  qhead = 0; qtail = 1; q[qtail] = 1;
  while (qhead != qtail) {
    qhead = (qhead + 1) % N;
    int i = q[qhead];
    for (int j = head[i]; j; j = next[j]) {
      int t1 = dis[i] + l[j];
      if (v[j] != n && tr[v[j]].count(t1)) t1 = tr[v[j]][t1];
      if (dis[v[j]] > t1) {
        dis[v[j]] = t1;
        if (!inque[v[j]]) {
          qtail = (qtail + 1) % N;
          q[qtail] = v[j];
          inque[v[j]] = true;
        }
      }
    }
    inque[i] = false;
    //printf("%d %d %d\n", qhead, q[qhead], dis[i]);
  }
  if (dis[n] == INF) puts("-1"); else printf("%d\n", dis[n]);
  return 0;
}