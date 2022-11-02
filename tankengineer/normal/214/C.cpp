#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, t1, top, v[45000], next[45000], head[500], c[500], dgr[500], d[500], ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &t1);
      ++top; v[top] = i; next[top] = head[t1]; head[t1] = top;
      ++dgr[i];
    }
  }
  ans = 2000000000;
  for (int i = 1; i <= 3; ++i) {
    int cmt = i, cnt = n, tmp = 0;
    for (int j = 1; j <= n; ++j) {
      d[j] = dgr[j];
    }
    while (cnt) {
      bool f = false;
      for (int j = 1; j <= n; ++j) {
        if (d[j] == 0 && c[j] == cmt) {
          d[j] = -1;
          --cnt;
          tmp += 1;
          f = true;
          for (int k = head[j]; k; k = next[k]) {
            --d[v[k]];
          }
        }
      }
      if (!f) {
        tmp ++;
        cmt ++;
        if (cmt == 4) cmt = 1;
      }
    }
    ans = min(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}