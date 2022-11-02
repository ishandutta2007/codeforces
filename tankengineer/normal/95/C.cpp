//77C
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const long long INF_low = 1 << 30, INF = INF_low << 30; 

long long n, m, start, termi, t1, t2, t3, top, v[2000000], head[1005], next[2000000], l[2000000], dis[1005][1005], qhead, qtail, q[1005], ans[1005], cnt;
bool inque[1005];

int main() {
  //freopen("77C.in", "r", stdin);
  //freopen("77C.out", "w", stdout);
  memset(head, 0, sizeof(head));
  scanf("%I64d %I64d %I64d %I64d", &n, &m, &start, &termi);
  n++;
  for (int i = 1; i <= m; i++) {
    scanf("%I64d %I64d %I64d", &t1, &t2, &t3);
    top++; v[top] = t2; next[top] = head[t1]; head[t1] = top; l[top] = t3;
    top++; v[top] = t1; next[top] = head[t2]; head[t2] = top; l[top] = t3;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = INF;
      inque[j] = false;
    }
    dis[i][i] = 0;
    qhead = 0; qtail = 1; q[qtail] = i; inque[i] = true;
    while (qhead != qtail) {
      cnt++;
      t1 = q[(qhead = (qhead + 1) % n)];
      for (int j = head[t1]; j; j = next[j]) {
        if (dis[i][t1] + l[j] < dis[i][v[j]]) {
          dis[i][v[j]] = dis[i][t1] + l[j];
          if (!inque[v[j]]) {
            q[(qtail = (qtail + 1) % n)] = v[j];
            inque[v[j]] = true;
          }
        }
      }
      inque[t1] = false;
    }
  }
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d %d : %I64d\n", i, j, dis[i][j]);
    }
  }
  */
  top = 0;
  for (int i = 1; i < n; i++) {
    head[i] = 0;
    scanf("%I64d %I64d", &t1, &t2);
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (dis[i][j] <= t1) {
        top++; v[top] = j; next[top] = head[i]; head[i] = top; l[top] = t2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    inque[i] = false;
    ans[i] = INF;
  }
  qhead = 0; qtail = 1; q[qtail] = start; inque[start] = true; ans[start] = 0;
  while (qhead != qtail) {
    t1 = q[(qhead = (qhead + 1) % n)];
    for (int j = head[t1]; j; j = next[j]) {
      if (ans[t1] + l[j] < ans[v[j]]) {
        ans[v[j]] = ans[t1] + l[j];
        if (!inque[v[j]]) {
          q[(qtail = (qtail + 1) % n)] = v[j];
          inque[v[j]] = true;
        }
      }
    }
    inque[t1] = false;
  }
  if (ans[termi] != INF) printf("%I64d\n", ans[termi]); else puts("-1");
  return 0;
}