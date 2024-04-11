#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 200005, M = 500005;

int n, top, top2, d[N], len[N], v[M], next[M], head[N], l[M], ans, anss[N], tmp, sum[N];
bool vis[N];

void dfs(const int i) {
  vis[i] = true;
  sum[i] = 0;
  for (int j = head[i]; j; j = next[j]) {
    if (!vis[v[j]]) {
      d[v[j]] = d[i] + 1;
      len[v[j]] = len[i] + l[j];
      dfs(v[j]);
      sum[i] += sum[v[j]] + l[j];
    }
  }
}

int main() {
  scanf("%d", &n);
  int t1, t2;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d %d", &t1, &t2);
    ++top; v[top] = t2; next[top] = head[t1]; head[t1] = top; l[top] = 0;
    ++top; v[top] = t1; next[top] = head[t2]; head[t2] = top; l[top] = 1;
  }
  d[1] = 0;
  len[1] = 0;
  dfs(1);
  ans = sum[1];
  top2 = 1; anss[top2] = 1;
  for (int i = 2; i <= n; ++i) {
    tmp = sum[1] - len[i] + (d[i] - len[i]);
    if (tmp < ans) {
      ans = tmp;
      top2 = 1;
      anss[top2] = i;
    } else if (tmp == ans) {
      anss[++top2] = i;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i < top2; ++i) printf("%d ", anss[i]);
  printf("%d\n", anss[top2]);
  return 0;
}