#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 2505, M = 5505, K = 1000005, MK = 2000105;

int n, m, k, x[N], y[N], cx[N], cy[N], r[N], g[N][N], dgr[N], qhead, qtail, q[N], d[N], head[N], headq[N], v[M], vq[MK], next[M], nextq[MK], l[MK], fa[N],
    ans[K], top, qtop, t1, t2;
bool vis[N];

bool in (const int i, const int j) {
  long long dis1 = r[j] - r[i], dis2 = cx[j] - cx[i], dis3 = cy[j] - cy[i];
  if (dis1 < 0) return false;
  dis1 *= dis1;
  dis2 *= dis2; dis3 *= dis3;
  if (dis2 + dis3 < dis1) return true; else return false;
}

int find(const int i) {return fa[i] == i ? i : fa[i] = find(fa[i]);}
void merge(const int i, const int j) {fa[i] = j;}

void tarjan(const int i) {
  vis[i] = true;
  for (int j = head[i]; j; j = next[j]) {
    tarjan(v[j]);
    merge(v[j], i);
  }
  
  for (int j = headq[i]; j; j = nextq[j]) {
    if (vis[vq[j]]) {
      ans[l[j]] = d[i] + d[vq[j]] - 2 * d[find(vq[j])] - (i == vq[j] ? 0 : 2);
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &x[i], &y[i]);
  for (int i = 1; i <= m; ++i) scanf("%d %d %d", &r[i], &cx[i], &cy[i]);
  for (int i = m + 1; i <= n + m; ++i) {
    cx[i] = x[i - m];
    cy[i] = y[i - m];
    r[i] = 0;
  }
  m += n;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i != j) {
        if (in(j, i)) {
          //printf("%d in %d\n", j, i);
          g[i][j] = true;
          ++dgr[j];
        }
      }
    }
  }
  qhead = 0; qtail = 0;
  for (int i = 1; i <= m; ++i) {
    if (dgr[i] == 0) {
      q[++qtail] = i;
      d[i] = 1;
    }
  }
  while (qhead < qtail) {
    int i = q[++qhead];
    for (int j = 1; j <= m; ++j) {
      if (g[i][j]) {
        --dgr[j];
        if (dgr[j] == 0) {
          fa[j] = i;
          q[++qtail] = j;
          d[j] = d[i] + 1;
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (fa[i] == 0) fa[i] = m + 1;
    ++top; v[top] = i; next[top] = head[fa[i]]; head[fa[i]] = top;
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d %d", &t1, &t2);
    t1 += m - n; t2 += m - n;
    ++qtop; vq[qtop] = t2; nextq[qtop] = headq[t1]; headq[t1] = qtop; l[qtop] = i;
    ++qtop; vq[qtop] = t1; nextq[qtop] = headq[t2]; headq[t2] = qtop; l[qtop] = i;
  }
  for (int i = 1; i <= m + 1; ++i) {
    fa[i] = i;
  }
  tarjan(m + 1);
  for (int i = 1; i <= k; ++i) printf("%d\n", ans[i]);
  return 0;
}