//19E
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, t1, t2, top, v[20005], next[20005], head[10005], num[20005], vis[10005], e[10005], odd_cycle, odd_edge, stop, s[10005], f[10005], g[10005], col[10005];

void dfs(const int &i, const int &fa, const int &c) {
  vis[i] = 1; col[i] = c;
  for (int j = head[i]; j; j = next[j]) {
    if (v[j] == fa) continue;
    if (vis[v[j]] == 0) {
      e[v[j]] = num[j];
      dfs(v[j], i, 1 - c);
      f[i] += f[v[j]];
      g[i] += g[v[j]];
    } else if (vis[v[j]] == 1) {
      if (col[v[j]] == c) {
        g[i]++;
        odd_cycle++;
        odd_edge = num[j];
      } else {
        f[i]++;
      }
    } else {
      if (col[v[j]] == c) {
        g[i]--;
      } else {
        f[i]--;
      }
    }
  }
  vis[i] = 2;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t1, &t2);
    top++; v[top] = t2; next[top] = head[t1]; head[t1] = top; num[top] = i;
    top++; v[top] = t1; next[top] = head[t2]; head[t2] = top; num[top] = i;
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0, 0);
  if (odd_cycle == 0) {
    stop = m;
    for (int i = 1; i <= m; i++) s[i] = i;
  } else {
    if (odd_cycle == 1) s[++stop] = odd_edge;
    for (int i = 1; i <= n; i++) {
      if (e[i] && g[i] == odd_cycle && f[i] == 0) s[++stop] = e[i];
    }
    sort(s + 1, s + 1 + stop);
  }
  printf("%d\n", stop);
  for (int i = 1; i < stop; i++) printf("%d ", s[i]);
  if (stop > 0) printf("%d\n", s[stop]);
  return 0;
}